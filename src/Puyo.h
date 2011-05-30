#ifndef __PUYO__
#define __PUYO__

#include "PuyoEnum.h"

class Puyo {
private:
    Color c;
public:
    Puyo();
    Puyo(Color c);

    Color getColor();
    bool operator==(const Puyo &p);
};

#endif
