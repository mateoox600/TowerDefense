#pragma once

#include <vector>
#include "../Enemy.hpp"

class EnemyManager {
private:
    int currentWave = 0;
    int lastId = 0;
    std::vector<int> toSpawn;
    float spawnAccumulator = 0.0f;
    std::vector<Enemy> enemies;

public:
    void init();
    void reset();

    void update();
    void draw();

    std::vector<Enemy*> getEnemyInRadius(raylib::Vector2 position, int radius);

    Enemy* getEnemyById(int id);
};