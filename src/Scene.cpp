#include "Scene.h"
#include "PuyoEnum.h"
#include "PuyoCluster.h"

// ---- super class ----

Scene::~Scene() {}

SceneId Scene::doFrame(int keyset, Screen *scr) {
    if (!isActive) {
        activate();
        isActive = true;
    }
    processKey(keyset);
    SceneId sid = processFrame();
    writeTo(scr);
    if (sid != self) {
        inactivate();
        isActive = false;
    }
    return sid;
}

void Scene::processKey(int keyset) {
    if (keyset & KeyEmulation::UP)    { doUp(); }
    if (keyset & KeyEmulation::DOWN)  { doDown(); }
    if (keyset & KeyEmulation::LEFT)  { doLeft(); }
    if (keyset & KeyEmulation::RIGHT) { doRight(); }
    if (keyset & KeyEmulation::A)     { doA(); }
    if (keyset & KeyEmulation::B)     { doB(); }
    if (keyset & KeyEmulation::Y)     { doY(); }
    if (keyset & KeyEmulation::X)     { doX(); }
    if (keyset & KeyEmulation::L1)    {  }
    if (keyset & KeyEmulation::L2)    {  }
    if (keyset & KeyEmulation::R1)    {  }
    if (keyset & KeyEmulation::R2)    {  }
}

