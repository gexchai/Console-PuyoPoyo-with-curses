#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "Scene.h"
#include "PlayField.h"
#include "NextField.h"
#include "ScoreField.h"

class PlayScene : public Scene {
  private:
    PlayField *pfield;
    NextField *nfield;
    ScoreField *sfield;
    unsigned int cnt;
    bool isFallPuyoAnim;
    bool isFallPuyoCluster;
    bool isSetNext;
    bool isErase;
    bool isFlushPuyo;
    
  public:
    PlayScene();

    virtual SceneId processFrame();
    void activate();
    void inactivate();

    void writeTo(Screen *scr);
    void doA();
    void doB();
    void doX();
    void doY();
    void doUp();
    void doRight();
    void doDown();
    void doLeft();
};

#endif
