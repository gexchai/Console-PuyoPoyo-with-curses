#include "Keypad.h"

using namespace std;

Keypad* Keypad::instance = new Keypad();

Keypad::Keypad() {
    // TODO. read from configure file.
    kmap.insert(make_pair('i', KeyEmulation::UP));
    kmap.insert(make_pair('j', KeyEmulation::LEFT));
    kmap.insert(make_pair('m', KeyEmulation::DOWN));
    kmap.insert(make_pair('k', KeyEmulation::RIGHT));
    kmap.insert(make_pair('c', KeyEmulation::A));
    kmap.insert(make_pair('x', KeyEmulation::B));
    kmap.insert(make_pair('d', KeyEmulation::X));
    kmap.insert(make_pair('s', KeyEmulation::Y));
    kmap.insert(make_pair('q', KeyEmulation::START));
}

int Keypad::getKey() {
    int keyset = 0;
    int key;
    while ((key = getch()) != -1) {
        keyset |= kmap[(char)key];
    }
    return keyset;
}

Keypad *Keypad::getInstance() {
    return instance;
}
