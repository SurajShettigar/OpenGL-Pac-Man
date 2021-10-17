#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <SDL.h>

#include <memory>
#include <array>

#include "shader.h"
#include "shape.h"

using std::array;

// This game class runs a simple game loop
class Game {
   public:
    Game();
    virtual ~Game();

    void init(int screenWidth, int screenHeight);
    void load();
    void handleInputs();
    void update(float dt);
    void render();
    void clean();

    bool isRunning;
    bool isUpPressed {false};
    bool isLeftPressed {false};
    bool isRightPressed {false};
    bool isDownPressed {false};
    bool isCtrlPressed {false};
    int windowWidth, windowHeight;

   private:
    // Shape shape[10];
    float timeSinceStart;

    Matrix4 projection;
    Matrix4 view;
    Shader shader;
};

#endif