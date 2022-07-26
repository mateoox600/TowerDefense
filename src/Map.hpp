#pragma once

#include "raylib-cpp.hpp"
#include "Wave.hpp"
#include <vector>

struct Map {
    raylib::Vector2 start;
    std::vector<raylib::Vector2> path;
    std::vector<EnemyWave> waves;
};