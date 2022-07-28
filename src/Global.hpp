#pragma once

#include "Map.hpp"

class PathManager;
class EnemyManager;
class TowerManager;

struct Wave;

struct Global {

    Global() { }
    Global(
        PathManager* pathManager,
        EnemyManager* enemyManager,
        TowerManager* towerManager
    ) : pathManager(pathManager), enemyManager(enemyManager), towerManager(towerManager) { }

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
        },
        std::vector<EnemyWave> {
            EnemyWave {
                std::vector<int> { 0, 0, 0 },
                10,
                3.0f
            },
            EnemyWave {
                std::vector<int> { 0, 0, 0, 0, 0 },
                25,
                3.0f
            },
            EnemyWave {
                std::vector<int> { 1, 1, 0, 0, 0 },
                50,
                3.0f
            }
        }
    };

};

extern Global global;