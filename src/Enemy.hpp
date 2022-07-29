#pragma once

#include "raylib-cpp.hpp"
#include "Global.hpp"
#include "GameConstants.hpp"
#include "PathManager.hpp"

using namespace GameConstants;

class Enemy {
private:
    int id;
    float progress;
    float speed;
    float health;
    float maxHealth;
    raylib::Vector2 pathProgress = raylib::Vector2(0, 0);
    Color color = BLUE;
public:
    Enemy(int id, float defaultProgress, float speed, float health, Color color);

    void update();
    void draw();

    float getProgress();
    float getHealth();

    void damage(float damage);

    int getId();
};