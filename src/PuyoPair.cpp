#include "PuyoPair.h"

using namespace std;

// ---- sub class ----

const int PuyoPair::rx[] = { 0, -1,  0,  1};
const int PuyoPair::ry[] = { 1,  0, -1,  0};

PuyoPair::PuyoPair() {
    x = 2; y = 0;
    position = 0;
    pfpair.first  = new PuyoFloat(0, 0);
    pfpair.second = new PuyoFloat(0, 1);
}

PuyoPair::PuyoPair(PuyoFloat *f, PuyoFloat *s) {
    x = 0; y = 0;
    position = 0;
    pfpair.first  = f;
    pfpair.second = s;
}

PuyoPair::~PuyoPair() {
    delete pfpair.first;
    delete pfpair.second;
}

void PuyoPair::movePuyo(int x, int y) {
    this->x += x;
    this->y += y;
}

void PuyoPair::movePuyo(Direction d) {
    this->x = rx[(int)d];
    this->y = ry[(int)d];
}

void PuyoPair::rotatePuyo(Rotation r) {
    position += (int)r;
    if (position > 3) { position = 0; }
    if (position < 0) { position = 3; }
}

vector<PuyoFloat*> PuyoPair::getPuyos() {
    pfpair.first->setX(x);
    pfpair.first->setY(y);
    pfpair.second->setX(x + rx[position]);
    pfpair.second->setY(y + ry[position]);

    vector<PuyoFloat*> v;
    v.push_back(pfpair.first);
    v.push_back(pfpair.second);
    return v;
}
