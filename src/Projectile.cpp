
#include "Projectile.hpp"

#include "GameConstants.hpp"
#include "Global.hpp"
#include "Enemy.hpp"
#include "Tower.hpp"

using namespace GameConstants;

bool Projectile::update() {
    progress += 0.07;

    Tower* tower = global.towerManager.getTowerById(towerId);
    Enemy* enemy = global.enemyManager.getEnemyById(targetId);

    if(enemy == nullptr || tower == nullptr) {
        return true;
    }

    raylib::Vector2 from = tower->getPosition();
    raylib::Vector2 to = global.pathManager.getPointOnPath(enemy->getProgress());

    if(progress >= from.Distance(to)) {
        enemy->damage(tower->getDamage());
        return true;
    }

    return false;
}

void Projectile::draw() {
    raylib::Vector2 from = global.towerManager.getTowerById(towerId)->getPosition();
    raylib::Vector2 to = global.pathManager.getPointOnPath(global.enemyManager.getEnemyById(targetId)->getProgress());
    
    /*
    printf("x: %f, y: %f\n", from.x, from.y);
    printf("x: %f, y: %f\n", to.x, to.y);

    float alpha = (to.y - from.y) / (to.x - from.x);
    float beta = (from.y * to.x - from.x * to.y) / (to.x - from.x);

    float A = 1 + pow(alpha, 2);
    float B = -(2 * from.x) + 2 * alpha * beta - 2 * alpha * from.y;
    float C = pow(from.x, 2) + pow(from.y, 2) + pow(beta, 2) - 2 * beta * from.y - pow(progress, 2);

    float x = (sqrt(pow(beta, 2) - 4 * A * C) -  B) / (2 * A);
    float y = x * alpha + beta;

    printf("x: %f, y: %f\n", x, y);

    raylib::Vector2 position(x, y);
    */

    raylib::Vector2 position(from.x + (to.x - from.x) * (progress / from.Distance(to)), from.y + (to.y - from.y) * (progress / from.Distance(to)));
    (position * cellSize + halfCellOffset).DrawCircle(3, RED);
}