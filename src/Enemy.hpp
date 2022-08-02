#pragma once

#include "raylib-cpp.hpp"

class Enemy {
private:
    int id;
    int reward;
    float progress;
    float speed;
    float health;
    float maxHealth;
    raylib::Vector2 pathProgress = raylib::Vector2(0, 0);
    Color color = BLUE;
public:
    Enemy(int id, int reward, float defaultProgress, float speed, float health, Color color);

    void update();
    void draw();

    int getId();
    int getReward();
    float getProgress();
    float getHealth();

    void damage(float damage);
};