
#include "Tower.hpp"

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

    for (size_t i = projectiles.size(); i-- != 0;) {
        bool hit = projectiles[i].update();
        if(hit) {
            projectiles.erase(projectiles.begin() + i);
        }
    }
    
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
            projectiles.push_back(Projectile{
                0.0f, this, target
            });
            // target->damage(damage);
        }
    }else fireAccumulator = 0.0f;
    
}

void Tower::draw() {
    (position * cellSize + halfCellOffset).DrawCircle(cellSize / 2.5, GREEN);
    (position * cellSize + halfCellOffset).DrawPoly(6, cellSize / 4, 0, BLUE);

    for (size_t i = 0; i < projectiles.size(); i++) {
        projectiles[i].draw();
    }
}

raylib::Vector2 Tower::getPosition() {
    return position;
}