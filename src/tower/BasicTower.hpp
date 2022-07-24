#pragma once

#include "../Tower.hpp"

class BasicTower : public Tower {
private:
    
public:
    BasicTower(PathManager* pathManager, EnemyManager* enemyManager, raylib::Vector2 spawnPosition) : Tower(pathManager, enemyManager, spawnPosition, 4, 1.0f, 2.5f) {
        
    }
};