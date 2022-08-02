#pragma once

#include "../Tower.hpp"

class StrongTower : public Tower {
private:
    
public:
    StrongTower(int id, raylib::Vector2 spawnPosition) : Tower(id, spawnPosition, RED, 2, 3.0f, 4.0f) {
        
    }
};