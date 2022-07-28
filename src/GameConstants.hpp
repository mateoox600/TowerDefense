#pragma once

#include "raylib-cpp.hpp"
#include <vector>

namespace GameConstants {
    const int screenWidth = 1600;
    const int screenHeight = 900;

    const int cellSize = 40;
    const raylib::Vector2 halfCellOffset(cellSize / 2, cellSize / 2);

    const int footerSize = cellSize * 2 + 45;

    const raylib::Vector2 mapSize(floor(screenWidth / cellSize), floor((screenHeight - footerSize) / cellSize));
}