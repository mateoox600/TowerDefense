#pragma once

class PathManager;
class EnemyManager;
class TowerManager;

struct Global {

    PathManager* pathManager;
    EnemyManager* enemyManager;
    TowerManager* towerManager;

};

extern Global global;