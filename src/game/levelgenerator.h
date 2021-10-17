#ifndef LEVEL_GENERATOR_H
#define LEVEL_GENERATOR_H

#include "level.h"

class LevelGenerator
{
private:
    Level level;
public:
    LevelGenerator() = default;
    ~LevelGenerator() = default;

    Level Instantiate(Matrix4 projection, Matrix4 view);

};

#endif