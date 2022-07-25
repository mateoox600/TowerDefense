
#include "raylib-cpp.hpp"
#include "GameConstants.hpp"
#include "PathManager.hpp"
#include "EnemyManager.hpp"
#include "TowerManager.hpp"
#include <vector>
#include <math.h>

#include <iostream>

using namespace GameConstants;

int main(int argc, char *argv[]) {
    // Initialization
    //--------------------------------------------------------------------------------------

    raylib::Window window(screenWidth, screenHeight, "caribou");

    window.SetTargetFPS(60);

    PathManager pathManager(start, path);

    EnemyManager enemyManager(&pathManager);

    TowerManager towerManager(&pathManager, &enemyManager);

    while (!window.ShouldClose()) {
        // Update
        //----------------------------------------------------------------------------------

        enemyManager.update();
        towerManager.update();

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            window.ClearBackground(WHITE);

            for (size_t i = 0; i < mapSize.x + 1; i++) {
                DrawLine(cellSize * i, 0, cellSize * i, screenHeight, BLACK);
            }
            for (size_t j = 0; j < mapSize.y + 1; j++) {
                DrawLine(0, cellSize * j, screenWidth, cellSize * j, BLACK);
            }
            

            pathManager.draw();
            enemyManager.draw();
            towerManager.draw();

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();

    return 0;
}