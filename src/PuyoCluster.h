#ifndef __PUYO_CLUSTER__
#define __PUYO_CLUSTER__

#include <vector>
#include "PuyoFloat.h"
#include "Rotation.h"
#include "Direction.h"

class PuyoCluster {
  public:
    virtual void movePuyo(int x, int y) = 0;
    virtual void movePuyo(Direction d) = 0;
    virtual void rotatePuyo(Rotation r) = 0;
    virtual std::vector<PuyoFloat*> getPuyos() = 0;
};

#endif
