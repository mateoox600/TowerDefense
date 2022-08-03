#pragma once

#include "raylib-cpp.hpp"
#include "../Tower.hpp"
#include <vector>

class TowerManager {
private:
    int lastId = 0;
    int towerPlacingIndex = 0;
    std::vector<Tower> towers;

public:
    void reset();

    void update();
    void draw();

    void placeTower(Tower tower);
    void deleteTowerAt(raylib::Vector2 position);

    Tower* getTowerById(int id);
};