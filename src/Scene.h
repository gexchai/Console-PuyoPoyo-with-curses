#ifndef __SCENE__
#define __SCENE__

#include "Screen.h"
#include "SceneId.h"

class Scene {
  protected:
    bool isActive;
    SceneId self;
  public:
    virtual ~Scene();
    virtual SceneId doFrame(int keyset, Screen *scr);
    virtual void processKey(int keyset);
    virtual SceneId processFrame() = 0;
    virtual void activate() = 0;
    virtual void inactivate() = 0;

    virtual void writeTo(Screen *scr) = 0;
    virtual void doA() = 0;
    virtual void doB() = 0;
    virtual void doX() = 0;
    virtual void doY() = 0;
    virtual void doUp()    = 0;
    virtual void doRight() = 0;
    virtual void doDown()  = 0;
    virtual void doLeft()  = 0;
};

#endif
