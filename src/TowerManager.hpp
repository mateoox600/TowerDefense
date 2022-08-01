#pragma once

#include "raylib-cpp.hpp"
#include "EnemyManager.hpp"
#include "PathManager.hpp"
#include "Enemy.hpp"
#include "Tower.hpp"
#include "tower/BasicTower.hpp"
#include "tower/StrongTower.hpp"
#include <vector>

class TowerManager {
private:
    int lastId = 0;
    int towerPlacingIndex = 0;
    std::vector<Tower> towers{ };

public:

    void update();
    void draw();

    void placeTower(Tower tower);
    void deleteTowerAt(raylib::Vector2 position);

    Tower* getTowerById(int id);
};