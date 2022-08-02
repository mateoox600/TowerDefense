#pragma once

#include "raylib-cpp.hpp"

class PathManager {
private:
public:

    void draw();

    raylib::Vector2 getPointOnPath(float progress);
    bool isOutsidePath(float progress);
};