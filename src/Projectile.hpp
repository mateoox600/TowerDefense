#pragma once

#include "raylib-cpp.hpp"
#include "Global.hpp"
#include "Enemy.hpp"
#include <memory>

class Tower;

struct Projectile {
    float progress;
    int towerId;
    int targetId;

    bool update();
    void draw();
};