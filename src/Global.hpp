#pragma once

#include "Map.hpp"

class PathManager;
class EnemyManager;
class TowerManager;

struct Global {

    PathManager* pathManager;
    EnemyManager* enemyManager;
    TowerManager* towerManager;
    
    Map map {
        raylib::Vector2(2, 0),
        std::vector<raylib::Vector2> {
            raylib::Vector2( 0, 1 ),
            raylib::Vector2( 0, 1 ),
            raylib::Vector2( 1, 0 ),
            raylib::Vector2( 1, 0 ),
            raylib::Vector2( 1, 0 ),
            raylib::Vector2( 1, 0 ),
            raylib::Vector2( 1, 0 ),
            raylib::Vector2( 0, -1 ),
            raylib::Vector2( 1, 0 ),
            raylib::Vector2( 1, 0 ),
            raylib::Vector2( 1, 0 ),
            raylib::Vector2( 0, 1 ),
            raylib::Vector2( 0, 1 ),
            raylib::Vector2( 0, 1 ),
            raylib::Vector2( 0, 1 ),
            raylib::Vector2( 0, 1 ),
            raylib::Vector2( 0, 1 ),
            raylib::Vector2( -1, 0 ),
            raylib::Vector2( -1, 0 ),
            raylib::Vector2( -1, 0 ),
        }
    };

};

extern Global global;