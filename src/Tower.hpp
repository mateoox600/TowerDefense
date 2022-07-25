#pragma once

#include "raylib-cpp.hpp"
#include "Global.hpp"
#include "EnemyManager.hpp"
#include "GameConstants.hpp"
#include "PathManager.hpp"
#include <vector>

using namespace GameConstants;

class Tower {
private:
    raylib::Vector2 position;
    int range;
    float damage;
    float fireSpeed;
    float fireAccumulator = 0.0f;
    Enemy* target = nullptr;

public:
    Tower(raylib::Vector2 position, int range, float damage, float fireSpeed);

    void update();
    void draw();

    raylib::Vector2 getPosition();
};