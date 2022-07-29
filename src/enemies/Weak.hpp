#pragma once

#include "../Enemy.hpp"

class Weak : public Enemy {
private:
    
public:
    Weak(int id, float startProgress) : Enemy(id, startProgress, 0.01f, 3.0f, VIOLET) {
        
    }
};