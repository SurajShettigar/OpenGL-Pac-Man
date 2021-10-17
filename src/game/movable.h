#ifndef MOVABLE_H
#define MOVABLE_H

#include "block.h"

class Movable : Block
{
private:
    bool isColliding {false};
public:
    float speed{1.0f};
    Vector3 direction{0.0f, 0.0f, 1.0f};
    void Move(float deltaTime);
    bool CheckCollision(Block &otherBlock);
};

#endif