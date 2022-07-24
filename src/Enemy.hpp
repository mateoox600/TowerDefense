#pragma once

#include "raylib-cpp.hpp"
#include "GameConstants.hpp"
#include "PathManager.hpp"

using namespace GameConstants;

class Enemy {
private:
    float progress;
    float speed;
    float health;
    float maxHealth;
    PathManager* pathManager;
    raylib::Vector2 pathProgress = raylib::Vector2(0, 0);
    Color color = BLUE;
public:
    Enemy(float defaultProgress, float speed, float health, PathManager* pathManager, Color color);

    void update();
    void draw();

    float getProgress();
    float getHealth();

    void damage(float damage);
};