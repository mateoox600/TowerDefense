#pragma once

#include "managers/PathManager.hpp"
#include "managers/EnemyManager.hpp"
#include "managers/TowerManager.hpp"

enum GameState {
    Playing, Dead
};

struct Global {

    Global() { }
    Global(
        raylib::Window* window
    ) : window(window) { }

    void init();
    void reset();

    raylib::Window* window;
    
    PathManager pathManager;
    EnemyManager enemyManager;
    TowerManager towerManager;

    GameState gameState = Playing;

    int lives = 25;
    int money = 250;

};

extern Global global;