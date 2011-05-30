#include "Screen.h"
#include <curses.h>
#include <iostream>

Screen::Screen(int width, int height) {
    this->width = width;
    this->height = height;
    this->blankChar = '.';
    // このクラスでは、出力通りにデータを保持する
    // x --> width, y --> height
    screen = new char*[height];
    for (int i = 0; i < height; i++) {
        screen[i] = new char[width];
        memset(screen[i], blankChar, sizeof(char) * width);
    }
}

bool Screen::writePixel(int y, int x, char c) {
    if ((x < 0 || x >= width) || (y < 0 || y >= height)) {
        return false;
    }
    screen[y][x] = c;
    return true;
}

bool Screen::writeLinePixels(int y, int x, const char *c) {
    int length = strlen(c);
    if ((x < 0 || (x + length - 1) >= width) || (y < 0 || y >= height)) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        screen[y][x + i] = c[i];
    }
    return true;
}

void Screen::flash() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            switch (screen[i][j]) {
            case 'G':
                attrset(COLOR_PAIR(3));
                break;
            case 'B':
                attrset(COLOR_PAIR(2));
                break;
            case 'R':
                attrset(COLOR_PAIR(1));
                break;
            case 'Y':
                attrset(COLOR_PAIR(4));
                break;
            case 'C':
                attrset(COLOR_PAIR(5));
                break;
            case 'M':
                attrset(COLOR_PAIR(6));
                break;
            default:
                attrset(COLOR_PAIR(0));
                break;
            }
            mvaddch(i, j, screen[i][j]);
        }
    }
}

void Screen::initScreen() {
    initscr(); cbreak(); noecho();
    start_color();
    init_pair(1, COLOR_RED,     COLOR_BLACK);
    init_pair(2, COLOR_BLUE,    COLOR_BLACK);
    init_pair(3, COLOR_GREEN,   COLOR_BLACK);
    init_pair(4, COLOR_YELLOW,  COLOR_BLACK);
    init_pair(5, COLOR_CYAN,    COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    bkgd(COLOR_PAIR(0));
    keypad(stdscr, true);

    leaveok(stdscr, TRUE);
    scrollok(stdscr, FALSE);
    wtimeout(stdscr, 1);
}

void Screen::finalizeScreen() {
    endwin();
}

void Screen::refreshScreen() {
    refresh();
}

void Screen::eraseScreen() {
    for (int i = 0; i < height; i++) {
        memset(screen[i], blankChar, sizeof(char) * width);
    }
}

void Screen::setBlankChar(char b) {
    this->blankChar = b;
}

