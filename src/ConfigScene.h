#ifndef __CONFIG_SCENE__
#define __CONFIG_SCENE__

#include "Scene.h"
#define CONFIG_NUMBER 2

class ConfigScene : public Scene {
  private:
    bool isNext;
    int cursor;
    int* params[CONFIG_NUMBER];
    int paramMax[CONFIG_NUMBER];
    int paramMin[CONFIG_NUMBER];
  public:
    ConfigScene();

    SceneId processFrame();
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
