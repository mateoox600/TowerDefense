#pragma once

#include "../Enemy.hpp"

class Weak : public Enemy {
private:
    
public:
    Weak(float startProgress, PathManager* pathManager) : Enemy(startProgress, 0.01f, pathManager, VIOLET) {
        
    }
};