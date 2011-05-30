#include <iostream>
#include "Game.h"
#include "PlayScene.h"
#include "ConfigScene.h"
#include "TitleScene.h"

using namespace std;

Game::Game() {
    scr = new Screen(SCREEN_MAX_WIDTH, SCREEN_MAX_HEIGHT);
    kp = Keypad::getInstance();
}

Game::~Game() {
    delete scr;

    map<SceneId, Scene*>::iterator itr = sceneMap.begin();
    while( itr != sceneMap.end() ) {
        delete (*itr).second;
        ++itr;
    }
}

void Game::initGame() {
    sceneMap.insert(make_pair(TITLE_SCENE,  new TitleScene()));
    sceneMap.insert(make_pair(PLAY_SCENE,   new PlayScene()));
    sceneMap.insert(make_pair(CONFIG_SCENE, new ConfigScene()));
    currentScene = sceneMap[TITLE_SCENE];
}

void Game::play() {
    scr->initScreen();
    while (true) {
        int keyset = kp->getKey();
        if (keyset == KeyEmulation::START) { break; }

        SceneId nextScene = currentScene->doFrame(keyset, scr);
        //currentScene->writeTo(scr);
        currentScene = sceneMap[nextScene];

        // TODO. ここに書きたくない。
        if      (nextScene == TITLE_SCENE)  { scr->setBlankChar(' '); }
        else if (nextScene == CONFIG_SCENE) { scr->setBlankChar(' '); }
        else if (nextScene == PLAY_SCENE)   { scr->setBlankChar('@'); }

        scr->flash();
        scr->refreshScreen();
        scr->eraseScreen();

        usleep(20000);
    }
    scr->finalizeScreen();
}
