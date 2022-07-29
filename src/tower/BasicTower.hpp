#pragma once

#include "../Tower.hpp"

class BasicTower : public Tower {
private:
    
public:
    BasicTower(int id, raylib::Vector2 spawnPosition) : Tower(id, spawnPosition, 4, 1.0f, 2.5f) {
        
    }
};