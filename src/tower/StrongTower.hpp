#pragma once

#include "../Tower.hpp"

class StrongTower : public Tower {
private:
    
public:
    StrongTower(int id, raylib::Vector2 spawnPosition) : Tower(id, 1, spawnPosition, 2, 3.0f, 4.0f) {
        
    }
};