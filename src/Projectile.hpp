#pragma once

#include "raylib-cpp.hpp"
#include "Global.hpp"
#include "Enemy.hpp"

class Tower;

struct Projectile {
    float progress;
    Tower* tower;
    Enemy* target;

    bool update();
    void draw();
};