
#include "PathManager.hpp"

PathManager::PathManager(raylib::Vector2 startPoint, std::vector<raylib::Vector2> path) : path(path), startPoint(startPoint) {

}

void PathManager::draw() {
    raylib::Vector2 accumulator = startPoint;
    for(size_t i = 0; i < path.size(); i++) {
        raylib::Vector2 nextPoint = accumulator + path[i];
        DrawLineEx(accumulator * cellSize + halfCellOffset, nextPoint * cellSize + halfCellOffset, 5, BLACK);
        accumulator = nextPoint;
    }

    DrawRectangle(startPoint.x * cellSize, startPoint.y * cellSize, cellSize, cellSize, GREEN);
    DrawRectangle(accumulator.x * cellSize, accumulator.y * cellSize, cellSize, cellSize, RED);
}

raylib::Vector2 PathManager::getPointOnPath(float progress) {
    raylib::Vector2 accumulator = startPoint;
    for(size_t i = 0; progress > 0; i++, progress--) {
        if(i >= path.size()) return raylib::Vector2(-420, -420);
        accumulator += path[i] * std::min(progress, 1.0f);
    }
    return accumulator;
}

bool PathManager::isOutsidePath(float progress) {
    return progress > path.size();
}