
#include "Projectile.hpp"
#include "Tower.hpp"
#include "TowerManager.hpp"

bool Projectile::update() {
    progress += 0.07;
    if(progress >= 1) {
        global.enemyManager->getEnemyById(targetId)->damage(1);
        return true;
    }
    return false;
}

void Projectile::draw() {
    raylib::Vector2 from = global.towerManager->getTowerById(towerId)->getPosition() * cellSize + halfCellOffset;
    raylib::Vector2 to = global.pathManager->getPointOnPath(global.enemyManager->getEnemyById(targetId)->getProgress()) * cellSize + halfCellOffset;
    raylib::Vector2 position(from.x + (to.x - from.x) * progress, from.y + (to.y - from.y) * progress);
    position.DrawCircle(3, RED);
}