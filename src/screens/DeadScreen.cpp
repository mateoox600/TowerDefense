
#include "DeadScreen.hpp"

#include "raylib-cpp.hpp"
#include "../GameConstants.hpp"
#include "../Global.hpp"

using namespace GameConstants;

void DeadScreen::update() {
    if(IsKeyPressed(KEY_ENTER)) global.reset();
}

void DeadScreen::draw() {

    // Ui
    //----------------------------------------------------------------------------------

    DrawCircleGradient(screenWidth / 2, screenHeight / 2, screenWidth, raylib::Color(255, 230, 230), RED);

    // "You died !" text
    //----------------------------------------------------------------------------------
    std::string diedStr = "You died !";
    float diedWidth = MeasureText(diedStr.c_str(), footerSize);
    DrawText(diedStr.c_str(), screenWidth / 2 - diedWidth / 2, screenHeight / 2 - footerSize / 2, footerSize, BLACK);

    // "Press ENTER to restart the game" text
    //----------------------------------------------------------------------------------
    std::string restartStr = "Press ENTER to restart the game";
    float restartWidth = MeasureText(restartStr.c_str(), cellSize);
    DrawText(restartStr.c_str(), screenWidth / 2 - restartWidth / 2, screenHeight / 2 + footerSize / 2, cellSize, BLACK);

    //----------------------------------------------------------------------------------
    // Ui end
}