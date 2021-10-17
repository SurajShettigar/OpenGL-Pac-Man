#include "movable.h"

void Movable::Move(float deltaTime)
{
    if (!isColliding)
    {
        Vector3 currPos = shape.transform.getTranslation();
        Vector3 pos = currPos + (direction * speed) * deltaTime;
        Movable::Update(pos);
    }
}

bool Movable::CheckCollision(Block& otherBlock)
{
    bool isXAxis = getPosition().x + getScale().x >= otherBlock.getPosition().x &&
        otherBlock.getPosition().x + otherBlock.getScale().x >= getPosition().x;
        
    bool isYAxis = getPosition().y + getScale().y >= otherBlock.getPosition().y &&
        otherBlock.getPosition().y + otherBlock.getScale().y >= getPosition().y;

    bool isZAxis = getPosition().z + getScale().z >= otherBlock.getPosition().z &&
        otherBlock.getPosition().z + otherBlock.getScale().z >= getPosition().z;

    isColliding = isXAxis && isYAxis && isZAxis;
    
    return isColliding;
}