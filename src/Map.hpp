#pragma once

#include "raylib-cpp.hpp"
#include <vector>

struct Map {
    raylib::Vector2 start;
    std::vector<raylib::Vector2> path;
};