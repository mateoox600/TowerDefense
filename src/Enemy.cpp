
#include "Enemy.hpp"

Enemy::Enemy(
    float defaultProgress,
    float speed,
    float health,
    PathManager* pathManager,
    Color color):
        progress(defaultProgress),
        speed(speed),
        maxHealth(health),
        health(health),
        pathManager(pathManager),
        color(color) { }

void Enemy::update() {
    progress += speed;
}

void Enemy::draw() {
    raylib::Vector2 point = (pathManager->getPointOnPath(progress) * cellSize + halfCellOffset);
    point.DrawCircle(cellSize / 2.5, color);
    float healthPercentage = health / maxHealth;
    (point - raylib::Vector2(cellSize / 2, cellSize / 2)).DrawRectangle(raylib::Vector2(cellSize * healthPercentage, cellSize / 10), RED);
}

float Enemy::getProgress() {
    return progress;
}

float Enemy::getHealth() {
    return health;
}

void Enemy::damage(float damage) {
    health -= damage;
}