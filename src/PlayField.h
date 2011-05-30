#ifndef __PLAY_FIELD__
#define __PLAY_FIELD__

#include "Field.h"
#include "Puyo.h"
#include "PuyoCluster.h"

#include "Rotation.h"

class PlayField : public Field {
private:
    static const int dh[];
    static const int dw[];
    static const int ry[][4];
    static const int rx[][4];

    int width, height;
    Puyo ***board;
    PuyoCluster *puyos;

public:
    PlayField(int width, int height);
    ~PlayField();

    void flushPuyo(Puyo *p, int x, int y);
    void flushPuyo(PuyoFloat *pf);
    void flushPuyo();

    void setPuyoCluster(PuyoCluster *puyos);

    void movePuyoCluster(int x, int y);
    void rotatePuyoCluster(Rotation r);
    void removePuyoCluster();
    bool isFallenPuyoCluster();
    bool isAbleMovePuyoCluster(int x, int y);
    bool isAbleRotatePuyoCluster(Rotation r);
    bool isAbleFallPuyoCluster();
    void fallPuyoCluster();

    int erasePuyo(int x, int y);
    int erasePuyoCluster();
    int eraseAllPuyo();
    int fallPuyo();
    bool fallPuyoOne();
    bool isHang();

    void writeTo(Screen *scr);
};

#endif
