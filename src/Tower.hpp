#pragma once

#include "raylib-cpp.hpp"
#include "Global.hpp"
#include "EnemyManager.hpp"
#include "GameConstants.hpp"
#include "PathManager.hpp"
#include "Projectile.hpp"
#include <vector>
#include <memory>

using namespace GameConstants;

class Tower {
private:
    int id;
    int type;
    raylib::Vector2 position;
    int range;
    float damage;
    float fireSpeed;
    float fireAccumulator = 0.0f;
    std::vector<Projectile> projectiles{ };

public:
    Tower(int id, int type, raylib::Vector2 position, int range, float damage, float fireSpeed);

    void update();
    void draw();

    int getId();
    float getDamage();
    raylib::Vector2 getPosition();
};