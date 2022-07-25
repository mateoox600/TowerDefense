#pragma once

#include "../Tower.hpp"

class BasicTower : public Tower {
private:
    
public:
    BasicTower(raylib::Vector2 spawnPosition) : Tower(spawnPosition, 4, 1.0f, 2.5f) {
        
    }
};