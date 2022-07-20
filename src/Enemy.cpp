
#include "Enemy.hpp"

Enemy::Enemy(
    float defaultProgress,
    float speed,
    PathManager* pathManager,
    Color color):
        progress(defaultProgress),
        speed(speed),
        pathManager(pathManager),
        color(color) { }

bool Enemy::update() {
    progress += speed;
    return pathManager->isOutsidePath(progress);
}

void Enemy::draw() {
    (pathManager->getPointOnPath(progress) * cellSize + halfCellOffset).DrawCircle(cellSize / 2, color);
}