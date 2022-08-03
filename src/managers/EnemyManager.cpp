
#include "EnemyManager.hpp"

#include "../GameConstants.hpp"
#include "../Global.hpp"
#include "../enemies/Weak.hpp"
#include "../enemies/Medium.hpp"

void EnemyManager::init() {
    toSpawn = GameConstants::map.waves[currentWave].enemies;
}

void EnemyManager::reset() {
    currentWave = 0;
    lastId = 0;
    toSpawn.clear();
    spawnAccumulator = 0.0f;
    enemies.clear();

    init();
}

void EnemyManager::update() {

    spawnAccumulator += GetFrameTime();
    if(spawnAccumulator >= GameConstants::map.waves[currentWave].spawnInterval && toSpawn.size() > 0) {
        spawnAccumulator = 0.0f;
        switch (toSpawn[0]) {
        case 0:
            enemies.push_back(Weak(lastId, 0.0f));
            break;
        case 1:
            enemies.push_back(Medium(lastId, 0.0f));
            break;
        default:
            enemies.push_back(Weak(lastId, 0.0f));
            break;
        }
        lastId++;
        toSpawn.erase(toSpawn.begin());
    }

    for (size_t i = enemies.size(); i-- != 0;) {
        Enemy* enemy = &enemies[i];
        enemy->update();
        if(enemy->getHealth() <= 0.0f) {
            global.money += enemy->getReward();
            enemies.erase(enemies.begin() + i);
        }else if(global.pathManager.isOutsidePath(enemy->getProgress())) {
            global.lives -= enemy->getHealth();
            enemies.erase(enemies.begin() + i);
        }
    }

    if(toSpawn.size() <= 0 && enemies.size() <= 0) {
        global.money += GameConstants::map.waves[currentWave].reward;
        currentWave++;
        toSpawn = GameConstants::map.waves[currentWave].enemies;
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
        raylib::Vector2 enemyPosition = global.pathManager.getPointOnPath(enemy->getProgress()) + raylib::Vector2(0.5, 0.5);
        raylib::Vector2 distance = enemyPosition - position;
        if(distance.x >= -radius + 1 && distance.y >= -radius + 1 && distance.x <= radius && distance.y <= radius) {
            enemiesInRandius.push_back(enemy);
        }
    }

    return enemiesInRandius;
}

Enemy* EnemyManager::getEnemyById(int id) {
    for (size_t i = 0; i < enemies.size(); i++) {
        if(enemies[i].getId() == id) return &enemies[i];
    }
    return nullptr;
}