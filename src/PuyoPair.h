#ifndef __PUYO_PAIR__
#define __PUYO_PAIR__

#include "PuyoCluster.h"

class PuyoPair : public PuyoCluster {
  private:
    static const int rx[];
    static const int ry[];

    int x, y;
    int position;
    std::pair<PuyoFloat*, PuyoFloat*> pfpair;
  public:
    PuyoPair();
    PuyoPair(PuyoFloat *f, PuyoFloat *s);
    ~PuyoPair();
    void movePuyo(int x, int y);
    void movePuyo(Direction d);
    void rotatePuyo(Rotation r);
    std::vector<PuyoFloat*> getPuyos();
};

#endif
