#include "PlayScene.h"
#include "PuyoEnum.h"
#include "PuyoCluster.h"

PlayScene::PlayScene() {
    this->self = PLAY_SCENE;
}

SceneId PlayScene::processFrame() {
    // TODO. 制御が汚すぎる。
    static int sum = 0;

    if (cnt > 50) {
        cnt = 0;
        isFallPuyoCluster = true;
    }
    if (isFallPuyoCluster) {
        isFallPuyoCluster = false;

        if (pfield->isAbleFallPuyoCluster()) {
            pfield->fallPuyoCluster();
        } else {
            isFlushPuyo = true;
        }
    }
    if (isFlushPuyo) {
        isFlushPuyo = false;

        pfield->flushPuyo();
        pfield->removePuyoCluster();

        isFallPuyoAnim = true;
    }
    if (isFallPuyoAnim) {
        if (cnt > 5) {
            cnt = 0;
            isFallPuyoAnim = false;

            if (pfield->fallPuyoOne()) {
                isFallPuyoAnim = true;
            } else {
                isErase = true;
            }
        }
    }
    if (isErase) {
        isErase = false;

        int num = pfield->eraseAllPuyo();
        if (num > 0) {
            sum += num;
            num = 0;
            isFallPuyoAnim = true;
        } else {
            isSetNext = true;
        }
    }
    if (isSetNext) {
        cnt = 0;
        isSetNext = false;

        if (pfield->isHang()) {
            return TITLE_SCENE;
        }
        pfield->setPuyoCluster(nfield->getNextPuyo());
        nfield->standByPuyo();
        sfield->addScore(sum);
        sum = 0;
    }
    cnt++;
    // TODO.
    return PLAY_SCENE;
}

void PlayScene::activate() {
    pfield = new PlayField(6, 14);
    pfield->setX(2);
    pfield->setY(0);
    nfield = new NextField();
    nfield->setX(11);
    nfield->setY(2);
    sfield = new ScoreField();
    sfield->setX(11);
    sfield->setY(7);

    PuyoCluster *puyos = nfield->getNextPuyo();
    pfield->setPuyoCluster(puyos);
    nfield->standByPuyo();

    cnt = 0;
    isFallPuyoCluster = false;
    isFallPuyoAnim = false;
    isSetNext = false;
    isErase = false;
    isFlushPuyo = false;
}
void PlayScene::inactivate() {
    delete pfield;
    delete nfield;
    delete sfield;
}

void PlayScene::writeTo(Screen *scr) {
    pfield->writeTo(scr);
    nfield->writeTo(scr);
    sfield->writeTo(scr);
}

void PlayScene::doA() {
    if (pfield->isAbleRotatePuyoCluster(ROTATE_RIGHT)) {
        pfield->rotatePuyoCluster(ROTATE_RIGHT);
    }
}

void PlayScene::doB() {
    if (pfield->isAbleRotatePuyoCluster(ROTATE_LEFT)) {
        pfield->rotatePuyoCluster(ROTATE_LEFT);
    }
}

void PlayScene::doX() {}
void PlayScene::doY() {}
void PlayScene::doUp() {}

void PlayScene::doRight() {
    pfield->movePuyoCluster(1, 0);
}
void PlayScene::doDown() {
    pfield->movePuyoCluster(0, 1);
}
void PlayScene::doLeft() {
    pfield->movePuyoCluster(-1, 0);
}
