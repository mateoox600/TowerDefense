#pragma once

#include "../Enemy.hpp"

class Medium : public Enemy {
private:
    
public:
    Medium(float startProgress) : Enemy(startProgress, 0.01f, 5.0f, GRAY) {
        
    }
};