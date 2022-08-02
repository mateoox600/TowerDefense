
#include "Global.hpp"

void Global::init() {
    enemyManager.init();
}

void Global::reset() {
    gameState = Playing;

    lives = 25;
    money = 250;

    enemyManager.reset();
    towerManager.reset();
}