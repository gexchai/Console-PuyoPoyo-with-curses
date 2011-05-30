#ifndef __GAME__
#define __GAME__

#include <map>
#include "Screen.h"
#include "Scene.h"
#include "Keypad.h"
#include "SceneId.h"

#define SCREEN_MAX_WIDTH  20
#define SCREEN_MAX_HEIGHT 15

class Game {
  private:
    Screen *scr;
    Keypad *kp;
    Scene *currentScene;
    std::map<SceneId, Scene*> sceneMap;
  public:
    Game();
    ~Game();
    void initGame();
    void play();
};

#endif
