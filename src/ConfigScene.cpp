#include "ConfigScene.h"
#include "PuyoEnum.h"

extern int colorNumber;

ConfigScene::ConfigScene() {
    this->self = CONFIG_SCENE;
    params[0]   = &colorNumber;
    paramMax[0] = MAX_COLOR_NUMBER;
    paramMin[0] = MIN_COLOR_NUMBER;
    // TODO.
    params[1]   = new int(0);
    isNext = false;
    cursor = 0;
}

SceneId ConfigScene::processFrame() {
    if (isNext) { return TITLE_SCENE; }
    return CONFIG_SCENE;
}

void ConfigScene::activate() {
}

void ConfigScene::inactivate() {
    isNext = false;
}

void ConfigScene::writeTo(Screen *scr) {
    scr->writeLinePixels( 0, 0, "********************");
    scr->writeLinePixels(14, 0, "********************");
    scr->writeLinePixels( 2, 5, "COLOR NUM");
    scr->writeLinePixels( 4, 5, "EXIT");
    scr->writePixel( 2, 17, (char)(colorNumber + '0'));
    scr->writePixel( 2 + cursor * 2, 2, '@');
}

void ConfigScene::doA() {
    isNext = true;
}

void ConfigScene::doB() {
}

void ConfigScene::doX() {
}

void ConfigScene::doY() {
}

void ConfigScene::doUp() {
    cursor++;
    if (cursor < 0) { cursor = CONFIG_NUMBER - 1; }
    if (cursor >= CONFIG_NUMBER) { cursor = 0; }
}

void ConfigScene::doRight() {
    (*(params[cursor]))++;
    int max = paramMax[cursor];
    int min = paramMin[cursor];
    int param = *params[cursor];
    *params[cursor] = ((param - min + (max - min + 1)) % (max - min + 1)) + min;
}

void ConfigScene::doDown() {
    cursor--;
    if (cursor < 0) { cursor = CONFIG_NUMBER - 1; }
    if (cursor >= CONFIG_NUMBER) { cursor = 0; }
}

void ConfigScene::doLeft() {
    (*(params[cursor]))--;
    int max = paramMax[cursor];
    int min = paramMin[cursor];
    int param = *params[cursor];
    *params[cursor] = (param - min + (max - min + 1)) % (max - min + 1) + min;
}

