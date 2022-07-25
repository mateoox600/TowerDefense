#pragma once

#include <vector>
#include "Global.hpp"
#include "Enemy.hpp"
#include "enemies/Weak.hpp"

class EnemyManager {
private:
    std::vector<Enemy> enemies{};
    float spawnAccumulator = 5.0f;

public:

    void update();
    void draw();

    std::vector<Enemy*> getEnemyInRadius(raylib::Vector2 position, int radius);
};