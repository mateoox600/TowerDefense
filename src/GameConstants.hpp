#pragma once

#include "raylib-cpp.hpp"
#include <vector>

namespace GameConstants {
    const int screenWidth = 1600;
    const int screenHeight = 900;

    const int cellSize = 40;
    const raylib::Vector2 halfCellOffset(cellSize / 2, cellSize / 2);
    const raylib::Vector2 mapSize(floor(screenWidth / cellSize), floor(screenHeight / cellSize));
    
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
}