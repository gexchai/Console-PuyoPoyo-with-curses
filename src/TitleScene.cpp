#include "TitleScene.h"

// ---- sub class ----

TitleScene::TitleScene() {
    this->self = TITLE_SCENE;
    tfield = new TitleField(0, 2);
    nextScene = CONFIG_SCENE;
    isNext = false;
}

SceneId TitleScene::processFrame() {
    if (isNext) {
        isNext = false;
        return nextScene;
    } else {
        return TITLE_SCENE;
    }
}

void TitleScene::activate() {}

void TitleScene::inactivate() {}

void TitleScene::writeTo(Screen *scr) {
    tfield->writeTo(scr);
    scr->writeLinePixels( 9, 7, "START");
    scr->writeLinePixels(11, 7, "CONFIG");
    if (nextScene == PLAY_SCENE) {
        scr->writePixel(9, 5, '@');
    } else {
        scr->writePixel(11, 5, '@');
    }
}

void TitleScene::doA() {
    isNext = true;
}

void TitleScene::doB() {}
void TitleScene::doX() {}
void TitleScene::doY() {}

void TitleScene::doUp() {
    nextScene = PLAY_SCENE;
}

void TitleScene::doRight() {}
void TitleScene::doDown() {
    nextScene = CONFIG_SCENE;
}

void TitleScene::doLeft() {}
