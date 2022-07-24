#pragma once

#include <vector>
#include "Enemy.hpp"
#include "enemies/Weak.hpp"

class EnemyManager {
private:
    PathManager* pathManager;
    std::vector<Enemy> enemies{};
    float spawnAccumulator = 5.0f;

public:
    EnemyManager(PathManager* pathManager);

    void update();
    void draw();

    std::vector<Enemy*> getEnemyInRadius(raylib::Vector2 position, int radius);
};