#pragma once

#include "raylib-cpp.hpp"
#include "Projectile.hpp"

class Tower {
private:
    int id;
    raylib::Vector2 position;
    Color color;
    int range;
    float damage;
    float fireSpeed;
    float fireAccumulator = 0.0f;
    std::vector<Projectile> projectiles;

public:
    Tower(int id, raylib::Vector2 position, Color color, int range, float damage, float fireSpeed);

    void update();
    void draw();

    int getId();
    float getDamage();
    raylib::Vector2 getPosition();
};