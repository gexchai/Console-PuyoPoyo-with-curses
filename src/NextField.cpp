#include <vector>
#include "NextField.h"
#include "PuyoPair.h"
#include "PuyoFloat.h"
#include "Puyo.h"

using namespace std;

NextField::NextField() {
    this->width = 7;
    this->height = 4;
    this->nextPuyo = new PuyoPair();
    this->nextNextPuyo = new PuyoPair();
    setX(0);
    setY(0);
}

NextField::~NextField() {
    delete nextPuyo;
    delete nextNextPuyo;
}

PuyoCluster* NextField::getNextPuyo() {
    return nextPuyo;
}

void NextField::standByPuyo() {
    nextPuyo = nextNextPuyo;
    nextNextPuyo = new PuyoPair();
}

void NextField::writeTo(Screen *scr) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            scr->writePixel(getY() + j, getX() + i, '.');
        }
    }
    vector<PuyoFloat*> v = nextPuyo->getPuyos();
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
        scr->writePixel(getY() + i + 1, getX() + 2, c);
    }
    v = nextNextPuyo->getPuyos();
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
        scr->writePixel(getY() + i + 1, getX() + 4, c);
    }
}
