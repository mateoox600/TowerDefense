
#include "raylib-cpp.hpp"

#ifdef PLATFORM_WEB
    #include <emscripten/emscripten.h>
#endif

#include "GameConstants.hpp"
#include "Global.hpp"
#include "PathManager.hpp"
#include "EnemyManager.hpp"
#include "TowerManager.hpp"
#include <vector>
#include <math.h>

#include <iostream>

using namespace GameConstants;

Global global;

void InitGlobal(raylib::Window* window);
void UpdateDrawFrame();

int main(int argc, char *argv[]) {
    // Initialization
    //--------------------------------------------------------------------------------------
    raylib::Window window(screenWidth, screenHeight, "caribou");

    global = Global(&window);

    global.init();

#ifdef PLATFORM_WEB
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    global.window->SetTargetFPS(60);

    while (!global.window->ShouldClose()) {
        UpdateDrawFrame();
    }
#endif

    return 0;
}

void UpdateDrawFrame() {
    // Update
    //----------------------------------------------------------------------------------
    if(global.gameState == Playing) {
        global.enemyManager.update();
        global.towerManager.update();

        if(global.lives <= 0) {
            global.gameState = Dead;
        }
    }else if(global.gameState == Dead) {
        if(IsKeyPressed(KEY_ENTER)) global.reset();
    }

    // Draw
    //----------------------------------------------------------------------------------
    global.window->BeginDrawing();
        global.window->ClearBackground(WHITE);

        if(global.gameState == Playing) {

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

        }else if(global.gameState == Dead) {
            DrawCircleGradient(screenWidth / 2, screenHeight / 2, screenWidth, WHITE, RED);

            std::string diedStr = "You died !";
            float diedWidth = MeasureText(diedStr.c_str(), footerSize);
            DrawText(diedStr.c_str(), screenWidth / 2 - diedWidth / 2, screenHeight / 2 - footerSize / 2, footerSize, BLACK);

            std::string restartStr = "Press ENTER to restart the game";
            float restartWidth = MeasureText(restartStr.c_str(), cellSize);
            DrawText(restartStr.c_str(), screenWidth / 2 - restartWidth / 2, screenHeight / 2 + footerSize / 2, cellSize, BLACK);
        }

    global.window->EndDrawing();
}