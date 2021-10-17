#include "../engine/game.h"
#include "../engine/texture.h"
#include "../engine/shape.h"
#include "../engine/vector3.h"
#include "levelgenerator.h"
#include "constants.h"

#include <cstdlib>
#include <ctime>
#include <cmath>

Game::Game() : isRunning(false), windowWidth(0), windowHeight(0) {}

Game::~Game() {}

void Game::init(int screenWidth, int screenHeight)
{
    windowWidth = screenWidth;
    windowHeight = screenHeight;
    isRunning = true;
}

Level level;
void Game::load()
{
    std::srand((int)std::time(nullptr));

    projection = Matrix4::createPerspectiveFOV(70.0f, windowWidth, windowHeight, 0.1f, 1000.0f);
    // view = Matrix4::createLookAt(Vector3(-5.0f, 0.0f, -10.0f), Vector3::zero, Vector3::unitY);
    view = Matrix4::createTranslation(Vector3(-7.0f, 1.8f, -15.0f));
    Matrix4 rotView = Matrix4::createRotationX(Maths::toRadians(125.0f));
    view = view * rotView;

    LevelGenerator levelGen;
    level = levelGen.Instantiate(projection, view);

    // for (int i = 0; i < sizeof(shape) / sizeof(Shape); i++)
    // {
    //     shape[i].CreateShape();
    //     shape[i].projection = projection;
    // }

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    shader.compileVertexShader();
    shader.compileFragmentShader();
    shader.createShaderProgram();

    shader.use();
}

void Game::handleInputs()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning = false;
            }
            else if (event.key.keysym.sym == SDLK_w)
            {
                isUpPressed = true;
            }
            else if (event.key.keysym.sym == SDLK_s)
            {
                isDownPressed = true;
            }
            else if (event.key.keysym.sym == SDLK_a)
            {
                isLeftPressed = true;
            }
            else if (event.key.keysym.sym == SDLK_d)
            {
                isRightPressed = true;
            }
            if (event.key.keysym.sym == SDLK_LCTRL)
                isCtrlPressed = true;
            break;
        case SDL_KEYUP:
            if (event.key.keysym.sym == SDLK_w)
            {
                isUpPressed = false;
            }
            else if (event.key.keysym.sym == SDLK_s)
            {
                isDownPressed = false;
            }
            else if (event.key.keysym.sym == SDLK_a)
            {
                isLeftPressed = false;
            }
            else if (event.key.keysym.sym == SDLK_d)
            {
                isRightPressed = false;
            }
            if (event.key.keysym.sym == SDLK_LCTRL)
                isCtrlPressed = false;
            break;
        default:
            break;
        }
    }
}

void Game::update(float dt)
{
    timeSinceStart += dt;
    const float t = timeSinceStart * 0.3f;

    if (isUpPressed)
    {
        Matrix4 transT = Matrix4::createTranslation(Vector3(0.0f, dt * 2.0f, 0.0f));
        view = transT * view;
        level.view = view;
        LOG(LogLevel::Debug) << "Current View: "
                             << view.getTranslation().x
                             << ", " << view.getTranslation().y
                             << ", " << view.getTranslation().z;
    }
    else if (isDownPressed)
    {
        Matrix4 transT = Matrix4::createTranslation(Vector3(0.0, dt * -2.0f, 0.0f));
        view = transT * view;
        level.view = view;
        LOG(LogLevel::Debug) << "Current View: "
                             << view.getTranslation().x
                             << ", " << view.getTranslation().y
                             << ", " << view.getTranslation().z;
    }

    if (isCtrlPressed)
    {
        if (isUpPressed)
        {
            Matrix4 rot = Matrix4::createRotationX(dt*2.0f);
            view = view * rot;
            level.view = view;
        }
        else if (isDownPressed)
        {
            Matrix4 rot = Matrix4::createRotationX(dt*-2.0f);
            view = view * rot;
            level.view = view;
        }
    }

    level.AnimatePoints(t * 45.0f);

    // Vector3 pos(0.0f, 0.0f, 0.0f);
    // Vector3 rot(t * 45.0f / 10.0f, t * 81.0f / 10.0f, 0.0);
    // Vector3 scale = Vector3::one;
    // for (int i = 0; i < sizeof(shape) / sizeof(Shape); i++)
    // {
    //     scale = i % 2 == 0 ? Vector3::one * 0.5 : Vector3::one;

    //     pos = Vector3(static_cast<float>(i % 5), static_cast<float>(i / 5), -4.0f);
    //     pos += Vector3(Maths::sin(2.1f * t) * 0.5f,
    //                    Maths::cos(1.7f * t) * 0.5f,
    //                    Maths::sin(1.3f * t) * Maths::cos(1.5f * t) * 2.0f);
    //     shape[i].Transform(pos, rot, scale);
    // }
}

void Game::render()
{
    static const GLfloat bgColor[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, bgColor);

    // for (int i = 0; i < sizeof(shape) / sizeof(Shape); i++)
    // {
    //     shape[i].color = i % 2 == 0
    //                          ? Constants::COLOR_RED
    //                          : (i % 3 == 0
    //                                 ? Constants::COLOR_CYAN
    //                                 : Constants::COLOR_BLUE);
    //     shape[i].Draw(shader);
    // }
    level.RenderLevel(shader);
}

void Game::clean()
{
    // glDeleteVertexArrays(1, &vao);
    // for (int i = 0; i < sizeof(shape) / sizeof(Shape); i++)
    // {
    //     shape[i].Clean();
    // }
}