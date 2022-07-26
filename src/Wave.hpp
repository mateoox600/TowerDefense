#pragma once

#include <vector>

struct EnemyWave {
    std::vector<int> enemies;
    int reward;
    float spawnInterval;
};