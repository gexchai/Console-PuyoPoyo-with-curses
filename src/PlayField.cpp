#include <queue>
#include <vector>
#include "PlayField.h"

using namespace std;

const int PlayField::dh[] = { 1, 0,-1, 0};
const int PlayField::dw[] = { 0, 1, 0,-1};
const int ry[][4] = {{-1, -1,  1,  1}, {-1, -1,  1,  1}};
const int rx[][4] = {{ 1, -1, -1,  1}, {-1,  1,  1, -1}};

PlayField::PlayField(int width, int height) {
    this->width = width;
    this->height = height;
    // create board.
    board = new Puyo**[width];
    for (int i = 0; i < width; i++) {
        board[i] = new Puyo*[height];
        memset(board[i], NULL, sizeof(Puyo*) * height);
    }
    puyos = NULL;
    setX(0);
    setY(0);
}

PlayField::~PlayField() {
    for (int i = 0; i < width; i++) {
        delete [] board[i];
    }
    delete [] board;
}

void PlayField::flushPuyo(Puyo *p, int x, int y) {
    board[x][y] = new Puyo(*p);
}

void PlayField::flushPuyo(PuyoFloat *pf) {
    flushPuyo(pf->getPuyo(), pf->getX(), pf->getY());
}

void PlayField::flushPuyo() {
    vector<PuyoFloat*> v = puyos->getPuyos();
    for (unsigned int i = 0; i < v.size(); i++) {
        flushPuyo(v[i]);
    }
}

void PlayField::setPuyoCluster(PuyoCluster *puyos) {
    if (this->puyos != NULL) { delete this->puyos; }
    this->puyos = puyos;
}

void PlayField::movePuyoCluster(int x, int y) {
    if (isAbleMovePuyoCluster(x, y)) {
        this->puyos->movePuyo(x, y);
    }
}

void PlayField::rotatePuyoCluster(Rotation r) {
    this->puyos->rotatePuyo(r);
}

void PlayField::removePuyoCluster() {
    if (this->puyos != NULL) {
        delete this->puyos;
        this->puyos = NULL;
    }
}

bool PlayField::isFallenPuyoCluster() {
    vector<PuyoFloat*> v = puyos->getPuyos();
    bool ret = false;
    for (unsigned int i = 0; i < v.size(); i++) {
        if ((board[v[i]->getX()][v[i]->getY()] == NULL)) {
            ret = true;
        }
    }
    return ret;
}

bool PlayField::isAbleMovePuyoCluster(int x, int y) {
    if (puyos == NULL) { return false; }
    vector<PuyoFloat*> v = puyos->getPuyos();
    int ret = true;
    for (unsigned int i = 0; i < v.size(); i++) {
        int px = v[i]->getX();
        int py = v[i]->getY();
        if (!(px + x >= 0 && px + x < width &&
              py + y >= 0 && py + y < height) ||
            (board[px + x][py + y] != NULL)) {
            ret = false;
        }
    }
    return ret;
}

bool PlayField::isAbleRotatePuyoCluster(Rotation r) {
    if (puyos == NULL) { return false; }
    this->puyos->rotatePuyo(r);
    vector<PuyoFloat*> v = puyos->getPuyos();
    int ret = true;
    for (unsigned int i = 0; i < v.size(); i++) {
        int px = v[i]->getX();
        int py = v[i]->getY();
        if (!(px >= 0 && px < width &&
              py >= 0 && py < height) ||
            (board[px][py] != NULL)) {
            ret = false;
        }
    }
    this->puyos->rotatePuyo((Rotation)((int)r * -1));
    return ret;
}

bool PlayField::isAbleFallPuyoCluster() {
    vector<PuyoFloat*> v = puyos->getPuyos();
    bool ret = true;
    for (unsigned int i = 0; i < v.size(); i++) {
        if ((board[v[i]->getX()][v[i]->getY() + 1] != NULL) ||
            (v[i]->getY() + 1 >= height)) {
            ret = false;
        }
    }
    return ret;
}

void PlayField::fallPuyoCluster() {
    this->movePuyoCluster(0, 1);
}

int PlayField::erasePuyo(int x, int y) {
    bool flag = false;
    if (board[x][y] == NULL) { return false; }
    // initialize check board.
    bool **buf = new bool*[width];
    for (int i = 0; i < width; i++) {
        buf[i] = new bool[height];
        memset(buf[i], false, sizeof(bool) * height);
    }

    int num = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        pair<int, int> coord = q.front();
        q.pop();
        num++;
        Puyo *puyo = board[coord.first][coord.second];
        buf[coord.first][coord.second] = true;
        for (int i = 0; i < 4; i++) {
            if ((coord.first  + dw[i] >= 0) && (coord.first  + dw[i] < width) &&
                (coord.second + dh[i] >= 0) && (coord.second + dh[i] < height) &&
                (buf[coord.first + dw[i]][coord.second + dh[i]] == false) &&
                (board[coord.first + dw[i]][coord.second + dh[i]] != NULL) &&
                (*board[coord.first + dw[i]][coord.second + dh[i]] == *puyo)) {
                q.push(make_pair(coord.first + dw[i], coord.second + dh[i]));
            }
        }
    }
    if (num >= 4) {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (buf[i][j]) {
                    delete board[i][j];
                    board[i][j] = NULL;
                }
            }
        }
        flag = true;
    } else {
        num = 0;
    }
    delete [] buf;

    return num;
}

int PlayField::erasePuyoCluster() {
    int num = 0;
    vector<PuyoFloat*> v = puyos->getPuyos();
    for (unsigned int i = 0; i < v.size(); i++) {
        num += erasePuyo(v[i]->getX(), v[i]->getY());
    }
    return num;
}

int PlayField::eraseAllPuyo() {
    int num = 0;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            num += erasePuyo(i, j);
        }
    }
    return num;
}

int PlayField::fallPuyo() {
    int fallFlag = 0;
    for (int i = 0; i < width; i++) {
        int idx = height - 1;
        for (int j = height - 1; j >= 0; --j) {
            if (board[i][j] != NULL) {
                if (board[i][idx] == board[i][j]) {
                    fallFlag |= (1 << i);
                }
                board[i][idx--] = board[i][j];
            }
        }
        for (int j = idx; j >= 0; --j) {
            board[i][j] = NULL;
        }
    }
    return fallFlag;
}

bool PlayField::fallPuyoOne() {
    bool isModify = false;
    for (int i = 0; i < width; i++) {
        for (int j = height - 1; j >= 0; --j) {
            if (j < height - 1 &&
                board[i][j] != NULL &&
                board[i][j + 1] == NULL) {
                board[i][j + 1] = board[i][j];
                board[i][j] = NULL;
                isModify = true;
            }
        }
    }
    return isModify;
}

bool PlayField::isHang() {
    if (board[2][0] != NULL || board[2][1]) { return true; }
    return false;
}

void PlayField::writeTo(Screen *scr) {
    // flush board.
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            char c;
            if (board[i][j] != NULL) {
                Color color = board[i][j]->getColor();
                switch (color) {
                case RED:
                    c = 'R';
                    break;
                case GREEN:
                    c = 'G';
                    break;
                case BLUE:
                    c = 'B';
                    break;
                case YELLOW:
                    c = 'Y';
                    break;
                case CYAN:
                    c = 'C';
                    break;
                case MAGENTA:
                    c = 'M';
                    break;
                }
            } else {
                c = ' ';
            }
            scr->writePixel(getY() + j, getX() + i, c);
        }
    }
    // flush PuyoCluster.
    if (puyos == NULL) { return; }
    vector<PuyoFloat*> v = puyos->getPuyos();
    for (unsigned int i = 0; i < v.size(); i++) {
        Color color = v[i]->getPuyo()->getColor();
        char c;
        switch (color) {
        case RED:
            c = 'R';
            break;
        case GREEN:
            c = 'G';
            break;
        case BLUE:
            c = 'B';
            break;
        case YELLOW:
            c = 'Y';
            break;
        case CYAN:
            c = 'C';
            break;
        case MAGENTA:
            c = 'M';
            break;
        }
        scr->writePixel(getY() + v[i]->getY(), getX() + v[i]->getX(), c);
    }
}

