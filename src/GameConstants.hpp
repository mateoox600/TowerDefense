#pragma once

#include "raylib-cpp.hpp"
#include <vector>
#include "Map.hpp"

struct Wave;

namespace GameConstants {
    const int screenWidth = 1600;
    const int screenHeight = 900;

    const int cellSize = 40;
    const raylib::Vector2 halfCellOffset(cellSize / 2, cellSize / 2);

    const int footerSize = cellSize * 2 + 45;

    const raylib::Vector2 mapSize(floor(screenWidth / cellSize), floor((screenHeight - footerSize) / cellSize));
    
    const Map map {
        raylib::Vector2(2, 2),
        std::vector<raylib::Vector2> {
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
        },
        std::vector<EnemyWave> {
            EnemyWave {
                std::vector<int> { 0, 0, 0 },
                75,
                3.0f
            },
            EnemyWave {
                std::vector<int> { 0, 0, 0, 0, 0 },
                175,
                3.0f
            },
            EnemyWave {
                std::vector<int> { 0, 1, 1, 1, 1 },
                300,
                3.0f
            }
        }
    };
}