#pragma once

#include <vector>
#include "Global.hpp"
#include "Enemy.hpp"
#include "Wave.hpp"
#include "enemies/Weak.hpp"
#include "enemies/Medium.hpp"

class EnemyManager {
private:
    int currentWave = -1;
    std::vector<int> toSpawn{};
    float spawnAccumulator = 0.0f;
    std::vector<Enemy> enemies{};

public:

    void update();
    void draw();

    std::vector<Enemy*> getEnemyInRadius(raylib::Vector2 position, int radius);
};