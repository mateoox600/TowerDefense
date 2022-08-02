#pragma once

#include "raylib-cpp.hpp"

class Tower;

struct Projectile {
    float progress;
    int towerId;
    int targetId;

    bool update();
    void draw();
};