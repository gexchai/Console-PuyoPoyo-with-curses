#ifndef __NEXT_FIELD__
#define __NEXT_FIELD__

#include "Field.h"
#include "PuyoCluster.h"

class NextField : public Field {
  private:
    int width, height;
    PuyoCluster *nextPuyo, *nextNextPuyo;
  public:
    NextField();
    ~NextField();
    PuyoCluster *getNextPuyo();
    void standByPuyo();
    void writeTo(Screen *scr);
};

#endif
