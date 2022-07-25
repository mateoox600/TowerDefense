
#include "TowerManager.hpp"

TowerManager::TowerManager(PathManager* pathManager, EnemyManager* enemyManager) : pathManager(pathManager), enemyManager(enemyManager) {

}

void TowerManager::update() {

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        raylib::Vector2 mousePosition = GetMousePosition();
        raylib::Vector2 screenPosition = raylib::Vector2(
            floor(mousePosition.x / cellSize),
            floor(mousePosition.y / cellSize)
        );
        placeTower(BasicTower(pathManager, enemyManager, screenPosition));
    }

    for (size_t i = 0; i < towers.size(); i++) {
        towers[i].update();
    }
}

void TowerManager::draw() {
    for (size_t i = 0; i < towers.size(); i++) {
        towers[i].draw();
    }
}

void TowerManager::placeTower(Tower tower) {
    towers.push_back(tower);
}

void TowerManager::deleteTowerAt(raylib::Vector2 position) {
    for (size_t i = towers.size(); i-- != 0;) {
        Tower* tower = &towers[i];
        if(tower->getPosition() == position) {
            towers.erase(towers.begin() + i);
        }
    }
}