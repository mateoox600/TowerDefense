
#include "raylib-cpp.hpp"
#include "GameConstants.hpp"
#include "PathManager.hpp"
#include "EnemyManager.hpp"
#include "TowerManager.hpp"
#include "Global.hpp"
#include <vector>
#include <math.h>

#include <iostream>

using namespace GameConstants;

Global global;

int main(int argc, char *argv[]) {
    // Initialization
    //--------------------------------------------------------------------------------------

    raylib::Window window(screenWidth, screenHeight, "caribou");

    window.SetTargetFPS(60);

    PathManager pathManager;
    EnemyManager enemyManager;
    TowerManager towerManager;

    global = Global(
        &pathManager,
        &enemyManager,
        &towerManager);

    while (!window.ShouldClose()) {
        // Update
        //----------------------------------------------------------------------------------

        enemyManager.update();
        towerManager.update();

        // Draw
        //----------------------------------------------------------------------------------
        window.BeginDrawing();
            window.ClearBackground(WHITE);

            for (size_t i = 0; i < mapSize.x + 1; i++) {
                DrawLine(cellSize * i, 0, cellSize * i, screenHeight, BLACK);
            }
            for (size_t j = 0; j < mapSize.y + 1; j++) {
                DrawLine(0, cellSize * j, screenWidth, cellSize * j, BLACK);
            }

            DrawRectangle(0, screenHeight - footerSize, screenWidth, footerSize, GRAY);

            pathManager.draw();
            enemyManager.draw();
            towerManager.draw();

        window.EndDrawing();
    }

    return 0;
}