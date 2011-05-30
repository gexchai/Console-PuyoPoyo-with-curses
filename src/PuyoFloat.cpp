#include "PuyoFloat.h"

PuyoFloat::PuyoFloat(int x, int y) {
    this->p = new Puyo();
    this->x = x;
    this->y = y;
}

PuyoFloat::PuyoFloat(Puyo *p, int x, int y) {
    this->p = p;
    this->x = x;
    this->y = y;
}

PuyoFloat::~PuyoFloat() {
    delete p;
}

Puyo* PuyoFloat::getPuyo() { return p; }
int PuyoFloat::getX() { return x; }
int PuyoFloat::getY() { return y; }
void PuyoFloat::setX(int x) { this->x = x; }
void PuyoFloat::setY(int y) { this->y = y; }
void PuyoFloat::addX(int d) { x += d; }
void PuyoFloat::addY(int d) { y += d; }
