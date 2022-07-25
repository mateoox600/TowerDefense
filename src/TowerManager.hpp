#pragma once

#include "raylib-cpp.hpp"
#include "EnemyManager.hpp"
#include "PathManager.hpp"
#include "Tower.hpp"
#include "tower/BasicTower.hpp"
#include <vector>

class TowerManager {
private:
    PathManager* pathManager;
    EnemyManager* enemyManager;
    std::vector<Tower> towers{ };

public:
    TowerManager(PathManager* pathManager, EnemyManager* enemyManager);

    void update();
    void draw();

    void placeTower(Tower tower);
    void deleteTowerAt(raylib::Vector2 position);
};