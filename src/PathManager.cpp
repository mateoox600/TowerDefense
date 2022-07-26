
#include "PathManager.hpp"

void PathManager::draw() {
    raylib::Vector2 accumulator = global.map.start;
    for(size_t i = 0; i < global.map.path.size(); i++) {
        raylib::Vector2 nextPoint = accumulator + global.map.path[i];
        DrawLineEx(accumulator * cellSize + halfCellOffset, nextPoint * cellSize + halfCellOffset, 5, BLACK);
        accumulator = nextPoint;
    }

    DrawRectangle(global.map.start.x * cellSize, global.map.start.y * cellSize, cellSize, cellSize, GREEN);
    DrawRectangle(accumulator.x * cellSize, accumulator.y * cellSize, cellSize, cellSize, RED);
}

raylib::Vector2 PathManager::getPointOnPath(float progress) {
    raylib::Vector2 accumulator = global.map.start;
    for(size_t i = 0; progress > 0; i++, progress--) {
        if(i >= global.map.path.size()) return raylib::Vector2(-420, -420);
        accumulator += global.map.path[i] * std::min(progress, 1.0f);
    }
    return accumulator;
}

bool PathManager::isOutsidePath(float progress) {
    return progress > global.map.path.size();
}