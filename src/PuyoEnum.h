#ifndef __PUYO_ENUM__
#define __PUYO_ENUM__

#define COLOR_NUMBER 3
#define MIN_COLOR_NUMBER 2
#define MAX_COLOR_NUMBER 6

enum Color {
    RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA
};

namespace KeyEmulation {

    enum Key {
        UP     = (1 << 0),
        DOWN   = (1 << 1),
        LEFT   = (1 << 2),
        RIGHT  = (1 << 3),
        A      = (1 << 4),
        B      = (1 << 5),
        X      = (1 << 6),
        Y      = (1 << 7),
        L1     = (1 << 8),
        L2     = (1 << 9),
        R1     = (1 << 10),
        R2     = (1 << 11),
        START  = (1 << 12),
        SELECT = (1 << 13)
    };

}

#endif
