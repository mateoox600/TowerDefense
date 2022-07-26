#pragma once

#include "raylib-cpp.hpp"
#include "GameConstants.hpp"
#include "Global.hpp"
#include <vector>
#include <math.h>

using namespace GameConstants;

class PathManager {
private:
public:

    void draw();
    raylib::Vector2 getPointOnPath(float progress);
    bool isOutsidePath(float progress);
};