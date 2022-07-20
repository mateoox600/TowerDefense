#pragma once

#include "raylib-cpp.hpp"
#include "GameConstants.hpp"
#include <vector>
#include <math.h>

using namespace GameConstants;

class PathManager {
private:
    raylib::Vector2 startPoint;
    std::vector<raylib::Vector2> path;
public:
    PathManager(raylib::Vector2 startPoint, std::vector<raylib::Vector2> path);

    void draw();
    raylib::Vector2 getPointOnPath(float progress);
    bool isOutsidePath(float progress);
};