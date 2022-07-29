#pragma once

#include "../Enemy.hpp"

class Medium : public Enemy {
private:
    
public:
    Medium(int id, float startProgress) : Enemy(id, startProgress, 0.01f, 5.0f, GRAY) {
        
    }
};