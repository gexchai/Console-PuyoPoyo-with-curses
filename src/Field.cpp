#include "Field.h"

Field::Field() {}

Field::Field(int x, int y) {
    this->x = x;
    this->y = y;
}

int Field::getX() {
    return this->x;
}

int Field::getY() {
    return this->y;
}

void Field::setX(int x) {
    this->x = x;
}

void Field::setY(int y) {
    this->y = y;
}
