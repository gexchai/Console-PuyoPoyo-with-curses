#include <stdlib.h>
#include "Puyo.h"

int colorNumber = COLOR_NUMBER;

Puyo::Puyo() {
    int r = rand() % colorNumber;
    this->c = (Color)r;
}

Puyo::Puyo(Color c) { this->c = c; }

Color Puyo::getColor() {
    return this->c;
}

bool  Puyo::operator==(const Puyo &p) {
    return this->c == p.c;
}

