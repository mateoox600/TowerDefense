#pragma once

#include "raylib-cpp.hpp"
#include "GameConstants.hpp"
#include "PathManager.hpp"

using namespace GameConstants;

class Enemy {
private:
    float progress;
    float speed;
    PathManager* pathManager;
    raylib::Vector2 pathProgress = raylib::Vector2(0, 0);
    Color color = BLUE;
public:
    Enemy(float defaultProgress, float speed, PathManager* pathManager, Color color);

    bool update();
    void draw();
};