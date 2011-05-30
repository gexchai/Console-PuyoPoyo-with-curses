#ifndef __KEYPAD__
#define __KEYPAD__

#include "PuyoEnum.h"
#include <curses.h>
#include <map>

class Keypad {
  private:
    static Keypad *instance;
    std::map<char, KeyEmulation::Key> kmap;

    Keypad();
    Keypad(const Keypad &);
  public:
    static Keypad *getInstance();
    int getKey();
};

#endif
