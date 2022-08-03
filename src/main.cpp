
#include "raylib-cpp.hpp"

#ifdef PLATFORM_WEB
    #include <emscripten/emscripten.h>
#endif

#include "GameConstants.hpp"
#include "Global.hpp"
#include "screens/PlayingScreen.hpp"
#include "screens/DeadScreen.hpp"
#include <vector>
#include <math.h>

#include <iostream>

using namespace GameConstants;

Global global;

void InitGlobal(raylib::Window* window);
void UpdateDrawFrame();

int main(int argc, char *argv[]) {
    // Initialization
    //--------------------------------------------------------------------------------------
    raylib::Window window(screenWidth, screenHeight, "caribou");

    global = Global(&window);

    global.init();

#ifdef PLATFORM_WEB
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    global.window->SetTargetFPS(60);

    while (!global.window->ShouldClose()) {
        UpdateDrawFrame();
    }
#endif

    return 0;
}

void UpdateDrawFrame() {
    // Update
    //----------------------------------------------------------------------------------
    switch (global.gameState) {
        case Playing:
            PlayingScreen::update();
            break;
        case Dead:
            DeadScreen::update();
            break;
    }

    // Draw
    //----------------------------------------------------------------------------------
    global.window->BeginDrawing();
        global.window->ClearBackground(WHITE);

        switch (global.gameState) {
            case Playing:
                PlayingScreen::draw();
                break;
            case Dead:
                DeadScreen::draw();
                break;
        }

    global.window->EndDrawing();
}