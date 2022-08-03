
#include "PlayingScreen.hpp"

#include "raylib-cpp.hpp"
#include "../GameConstants.hpp"
#include "../Global.hpp"

using namespace GameConstants;

void PlayingScreen::update() {
    global.enemyManager.update();
    global.towerManager.update();

    if(global.lives <= 0) {
        global.gameState = Dead;
    }
}

void PlayingScreen::draw() {
    for (size_t i = 0; i < mapSize.x + 1; i++) {
        DrawLine(cellSize * i, 0, cellSize * i, screenHeight, BLACK);
    }
    for (size_t j = 0; j < mapSize.y + 1; j++) {
        DrawLine(0, cellSize * j, screenWidth, cellSize * j, BLACK);
    }

    DrawRectangle(0, screenHeight - footerSize, screenWidth, footerSize, GRAY);

    std::string livesLeft = TextFormat("%i", global.lives);
    float livesLeftTextWidth = raylib::MeasureText(livesLeft, footerSize - 20);
    DrawRectangle(screenWidth - footerSize - 30, screenHeight - footerSize + 10 , footerSize + 20, footerSize - 20, DARKGRAY);
    float livesLeftXPosition = screenWidth - footerSize - 30 + (footerSize + 20) / 2;
    raylib::DrawText(livesLeft, livesLeftXPosition - livesLeftTextWidth / 2, screenHeight - footerSize + 15, footerSize - 20, WHITE);

    std::string moneyString = TextFormat("%i", global.money);
    float moneyStringTextWidth = raylib::MeasureText(moneyString, footerSize - 20);

    raylib::Vector2 moneyStringPosition(screenWidth / 2 - moneyStringTextWidth / 2, screenHeight - footerSize + 10);

    DrawRectangle(moneyStringPosition.x - 10, moneyStringPosition.y, moneyStringTextWidth + 20, footerSize - 20, DARKGRAY);
    
    raylib::DrawText(moneyString, moneyStringPosition.x, moneyStringPosition.y + 5, footerSize - 20, WHITE);

    global.pathManager.draw();
    global.enemyManager.draw();
    global.towerManager.draw();
}