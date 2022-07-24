
#include "raylib-cpp.hpp"
#include "GameConstants.hpp"
#include "PathManager.hpp"
#include "EnemyManager.hpp"
#include "tower/BasicTower.hpp"
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

    BasicTower tower(&pathManager, &enemyManager, raylib::Vector2(8, 0));
    BasicTower tower1(&pathManager, &enemyManager, raylib::Vector2(3, 3));

    while (!window.ShouldClose()) {
        // Update
        //----------------------------------------------------------------------------------

        enemyManager.update();
        tower.update();
        tower1.update();

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
            tower.draw();
            tower1.draw();

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();

    return 0;
}