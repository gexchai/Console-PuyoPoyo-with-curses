#ifndef __TITLE_SCENE__
#define __TITLE_SCENE__

#include "Screen.h"
#include "Scene.h"
#include "TitleField.h"

class TitleScene : public Scene {
  private:
    TitleField *tfield;
    SceneId nextScene;
    bool isNext;
  public:
    TitleScene();
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
