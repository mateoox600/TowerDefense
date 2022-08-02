#pragma once

#include "Map.hpp"

class PathManager;
class EnemyManager;
class TowerManager;

struct Wave;

struct Global {

    Global() { }
    Global(
        raylib::Window* window,
        PathManager* pathManager,
        EnemyManager* enemyManager,
        TowerManager* towerManager
    ) : window(window), pathManager(pathManager), enemyManager(enemyManager), towerManager(towerManager) { }

    raylib::Window* window;
    
    PathManager* pathManager;
    EnemyManager* enemyManager;
    TowerManager* towerManager;

    int lives = 25;
    int money = 250;
    
    Map map {
        raylib::Vector2(2, 2),
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
        },
        std::vector<EnemyWave> {
            EnemyWave {
                std::vector<int> { 0, 0, 0 },
                75,
                3.0f
            },
            EnemyWave {
                std::vector<int> { 0, 0, 0, 0, 0 },
                175,
                3.0f
            },
            EnemyWave {
                std::vector<int> { 0, 1, 1, 1, 1 },
                300,
                3.0f
            }
        }
    };

};

extern Global global;