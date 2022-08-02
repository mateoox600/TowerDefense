
#include "Enemy.hpp"

Enemy::Enemy(
    int id,
    int reward,
    float defaultProgress,
    float speed,
    float health,
    Color color):
        id(id),
        reward(reward),
        progress(defaultProgress),
        speed(speed),
        maxHealth(health),
        health(health),
        color(color) { }

void Enemy::update() {
    progress += speed;
}

void Enemy::draw() {
    raylib::Vector2 point = (global.pathManager->getPointOnPath(progress) * cellSize + halfCellOffset);
    point.DrawCircle(cellSize / 2.5, color);
    float healthPercentage = health / maxHealth;
    (point - raylib::Vector2(cellSize / 2, cellSize / 2)).DrawRectangle(raylib::Vector2(cellSize * healthPercentage, cellSize / 10), RED);
}

int Enemy::getId() {
    return id;
}

int Enemy::getReward() {
    return reward;
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