#pragma once

#include "../Enemy.hpp"

class Weak : public Enemy {
private:
    
public:
    Weak(float startProgress) : Enemy(startProgress, 0.01f, 3.0f, VIOLET) {
        
    }
};