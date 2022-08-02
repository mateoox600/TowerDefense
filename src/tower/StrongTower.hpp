#pragma once

#include "../Tower.hpp"

class StrongTower : public Tower {
private:
public:
    static const int cost = 250;
    
    StrongTower(int id, raylib::Vector2 spawnPosition) : Tower(id, spawnPosition, RED, 2, 3.0f, 4.0f) {
        
    }
};