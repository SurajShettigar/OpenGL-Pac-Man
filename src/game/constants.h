#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "../engine/vector4.h"

enum class BlockType
{
    Wall,
    Gate,
    Point,
    Player,
    Enemy,
    Powerup
};

class Constants
{
public:
    static const Vector4 COLOR_BLACK;
    static const Vector4 COLOR_WHITE;
    static const Vector4 COLOR_GREY;
    static const Vector4 COLOR_RED;
    static const Vector4 COLOR_GREEN;
    static const Vector4 COLOR_BLUE;
    static const Vector4 COLOR_YELLOW;
    static const Vector4 COLOR_CYAN;
    static const Vector4 COLOR_MAGENTA;
    static const char* FILE_LEVEL;
};

#endif