
#include "EnemyManager.hpp"

void EnemyManager::update() {
    spawnAccumulator += GetFrameTime();

    if(spawnAccumulator >= 2.5f) {
        spawnAccumulator = 0.0f;
        enemies.push_back(Weak(0.0f));
    }

    for (size_t i = enemies.size(); i-- != 0;) {
        Enemy* enemy = &enemies[i];
        enemy->update();
        if(global.pathManager->isOutsidePath(enemy->getProgress()) || enemy->getHealth() <= 0.0f) {
            enemies.erase(enemies.begin() + i);
        }
    }
}

void EnemyManager::draw() {
    for (size_t i = 0; i < enemies.size(); i++) {
        enemies[i].draw();
    }
}

std::vector<Enemy*> EnemyManager::getEnemyInRadius(raylib::Vector2 position, int radius) {

    std::vector<Enemy*> enemiesInRandius{ };

    for(size_t i = 0; i < enemies.size(); i++) {
        Enemy* enemy = &enemies[i];
        raylib::Vector2 enemyPosition = global.pathManager->getPointOnPath(enemy->getProgress()) + raylib::Vector2(0.5, 0.5);
        raylib::Vector2 distance = enemyPosition - position;
        if(distance.x >= -radius + 1 && distance.y >= -radius + 1 && distance.x <= radius && distance.y <= radius) {
            enemiesInRandius.push_back(enemy);
        }
    }

    return enemiesInRandius;
}