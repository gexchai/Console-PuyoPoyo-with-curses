#include "ScoreField.h"

ScoreField::ScoreField() {
    width = 7;
    height = 7;
    score = 0;
    setX(0);
    setY(0);
}

void ScoreField::addScore(int score) {
    this->score += score;
}

void ScoreField::writeTo(Screen *scr) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            scr->writePixel(getY() + j, getX() + i, '.');
        }
    }
    scr->writeLinePixels(getY() + 1, getX() + 1, "SCORE");
    scr->writeLinePixels(getY() + 4, getX() + 1, "CHAIN");

    int s = score;
    for (int i = 0; i < 5; i++) {
        int c;
        int n = s % 10;
        s /= 10;
        switch (n) {
        case 0: c = '0'; break;
        case 1: c = '1'; break;
        case 2: c = '2'; break;
        case 3: c = '3'; break;
        case 4: c = '4'; break;
        case 5: c = '5'; break;
        case 6: c = '6'; break;
        case 7: c = '7'; break;
        case 8: c = '8'; break;
        case 9: c = '9'; break;
        }
        scr->writePixel(getY() + 2, getX() + 5 - i, c);
    }
}
