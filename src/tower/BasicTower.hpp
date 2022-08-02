#pragma once

#include "../Tower.hpp"

class BasicTower : public Tower {
private:
public:
    static const int cost = 100;

    BasicTower(int id, raylib::Vector2 spawnPosition) : Tower(id, spawnPosition, BLUE, 4, 1.0f, 2.5f) {
        
    }
};