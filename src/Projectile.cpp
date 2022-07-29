
#include "Projectile.hpp"
#include "Tower.hpp"

bool Projectile::update() {
    progress += 0.07;
    if(progress >= 1) {
        target->damage(1);
        return true;
    }
    return false;
}

void Projectile::draw() {
    raylib::Vector2 from = tower->getPosition() * cellSize + halfCellOffset;
    raylib::Vector2 to = global.pathManager->getPointOnPath(target->getProgress()) * cellSize + halfCellOffset;
    raylib::Vector2 position(from.x + (to.x - from.x) * progress, from.y + (to.y - from.y) * progress);
    position.DrawCircle(5, RED);
}