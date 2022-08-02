
#include "TowerManager.hpp"

void TowerManager::update() {

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        raylib::Vector2 mousePosition = GetMousePosition();
        if(mousePosition.y < screenHeight - footerSize) {
            raylib::Vector2 screenPosition = raylib::Vector2(
                floor(mousePosition.x / cellSize),
                floor(mousePosition.y / cellSize)
            );
            switch (towerPlacingIndex) {
                case 0:
                    placeTower(BasicTower(lastId, screenPosition));
                    break;
                case 1:
                    placeTower(StrongTower(lastId, screenPosition));
                    break;
                
                default:
                    placeTower(BasicTower(lastId, screenPosition));
                    break;
            }
            
            lastId++;
        }else if(mousePosition.x > 20 && mousePosition.x < 20 + 6 * (cellSize + 5) - 5 &&
                mousePosition.y > screenHeight - footerSize + 20 && mousePosition.y < screenHeight - 20) {
            raylib::Vector2 position(floor((mousePosition.x - 20) / (cellSize + 5)), floor((mousePosition.y - (screenHeight - footerSize + 20)) / (cellSize + 5)));
            int buttonIndex = position.x + position.y * 6;
            towerPlacingIndex = buttonIndex;
        }
    }

    for (size_t i = 0; i < towers.size(); i++) {
        towers[i].update();
    }
}

void TowerManager::draw() {
    for (size_t i = 0; i < towers.size(); i++) {
        Tower* tower = &towers[i];
        tower->draw();
    }

    DrawRectangle(10, screenHeight - footerSize + 10, (cellSize + 5) * 6 + 20 - 5, footerSize - 20, DARKGRAY);
    
    for (size_t i = 0; i < 12; i++) {
        raylib::Vector2 position(i % 6, floor(i / 6));
        raylib::Vector2 screenPosition(20 + position.x * (cellSize + 5), screenHeight - footerSize + 20 + position.y * (cellSize + 5));
        screenPosition.DrawRectangle(raylib::Vector2(cellSize, cellSize), RED);
    }
    
}

void TowerManager::placeTower(Tower tower) {
    towers.push_back(tower);
}

void TowerManager::deleteTowerAt(raylib::Vector2 position) {
    for (size_t i = towers.size(); i-- != 0;) {
        if(towers[i].getPosition() == position) {
            towers.erase(towers.begin() + i);
        }
    }
}

Tower* TowerManager::getTowerById(int id) {
    for (size_t i = 0; i < towers.size(); i++) {
        if(towers[i].getId() == id) return &towers[i];
    }
    return nullptr;
}