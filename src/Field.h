#ifndef __FIELD__
#define __FIELD__

#include "Screen.h"

class Field {
  private:
    int x, y;
  public:
    Field();
    Field(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    virtual void writeTo(Screen *scr) = 0;
};

#endif
