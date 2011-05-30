#ifndef __PUYO_FLOAT__
#define __PUYO_FLOAT__

#include "Puyo.h"

class PuyoFloat {
private:
    int x, y;
    Puyo *p;
public:
    PuyoFloat(int x, int y);
    PuyoFloat(Puyo *p, int x, int y);
    ~PuyoFloat();

    Puyo *getPuyo();
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void addX(int d);
    void addY(int d);
};

#endif
