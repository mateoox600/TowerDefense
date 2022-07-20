
#include "raylib-cpp.hpp"
#include "GameConstants.hpp"
#include "PathManager.hpp"
#include "Enemy.hpp"
#include "enemies/Weak.hpp"
#include <vector>
#include <math.h>

#include <iostream>

using namespace GameConstants;

int main(int argc, char *argv[]) {
    // Initialization
    //--------------------------------------------------------------------------------------

    raylib::Window window(screenWidth, screenHeight, "caribou");

    window.SetTargetFPS(60);

    const raylib::Vector2 start(2, 0);
    const std::vector<raylib::Vector2> path{
        raylib::Vector2( 0, 1 ),
        raylib::Vector2( 0, 1 ),
        raylib::Vector2( 1, 0 ),
        raylib::Vector2( 1, 0 ),
        raylib::Vector2( 1, 0 ),
        raylib::Vector2( 1, 0 ),
        raylib::Vector2( 1, 0 ),
        raylib::Vector2( 0, -1 ),
        raylib::Vector2( 1, 0 ),
        raylib::Vector2( 1, 0 ),
        raylib::Vector2( 1, 0 ),
        raylib::Vector2( 0, 1 ),
        raylib::Vector2( 0, 1 ),
        raylib::Vector2( 0, 1 ),
        raylib::Vector2( 0, 1 ),
        raylib::Vector2( 0, 1 ),
        raylib::Vector2( 0, 1 ),
        raylib::Vector2( -1, 0 ),
        raylib::Vector2( -1, 0 ),
        raylib::Vector2( -1, 0 ),
    };

    PathManager pathManager(start, path);

    std::vector<Enemy> enemies{ };

    float spawnAccumulator = 5.0f;

    while (!window.ShouldClose()) {
        // Update
        //----------------------------------------------------------------------------------

        for (size_t i = enemies.size(); i-- != 0;) {
            if(enemies[i].update()) {
                enemies.erase(enemies.begin() + i);
            }
        }

        spawnAccumulator += GetFrameTime();

        if(spawnAccumulator >= 2.5f) {
            spawnAccumulator = 0.0f;
            enemies.push_back(Weak(0.0f, &pathManager));
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            window.ClearBackground(WHITE);

            pathManager.draw();

            for (size_t i = 0; i < enemies.size(); i++) {
                enemies[i].draw();
            }

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();

    return 0;
}