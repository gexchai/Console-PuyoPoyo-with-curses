#include "TitleField.h"
#include <string>

TitleField::TitleField(int x, int y) : Field(x, y) {
    height =  5;
    width  = 20;
    titleBoard = new char*[height];
    titleBoard[0] = (char*)"@@@  @  @ @   @  @@ ";
    titleBoard[1] = (char*)"@  @ @  @ @   @ @  @";
    titleBoard[2] = (char*)"@  @ @  @  @ @  @  @";
    titleBoard[3] = (char*)"@@@  @  @   @   @  @";
    titleBoard[4] = (char*)"@     @@    @    @@ ";
}

void TitleField::writeTo(Screen *scr) {
    for (int i = 0; i < height; i++) {
        scr->writeLinePixels(getY() + i, getX(), titleBoard[i]);
    }
}
