
#include "Tower.hpp"

#include "iostream"

Tower::Tower(
    raylib::Vector2 position,
    int range,
    float damage,
    float fireSpeed):
        position(position),
        range(range),
        damage(damage),
        fireSpeed(fireSpeed) {

}

void Tower::update() {
    std::vector<Enemy*> enemiesInRange = global.enemyManager->getEnemyInRadius(position, range);

    target = nullptr;
    for (size_t i = 0; i < enemiesInRange.size(); i++) {
        if(target == nullptr)
            target = enemiesInRange[i];
        else if(enemiesInRange[i]->getProgress() > target->getProgress())
            target = enemiesInRange[i];
    }

    if(target != nullptr) {
        fireAccumulator += GetFrameTime();
        if(fireAccumulator >= fireSpeed) {
            fireAccumulator = 0.0f;
            target->damage(damage);
        }
    }else fireAccumulator = 0.0f;
    
}

void Tower::draw() {
    (position * cellSize + halfCellOffset).DrawCircle(cellSize / 2.5, GREEN);
    (position * cellSize + halfCellOffset).DrawPoly(6, cellSize / 4, 0, BLUE);
    if(target != nullptr)
        (position * cellSize + halfCellOffset).DrawLine((global.pathManager->getPointOnPath(target->getProgress()) * cellSize + halfCellOffset), 2, BLACK);
}

raylib::Vector2 Tower::getPosition() {
    return position;
}