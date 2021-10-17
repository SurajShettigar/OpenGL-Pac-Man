#ifndef BLOCK_H
#define BLOCK_H

#include "constants.h"
#include "../engine/vector3.h"
#include "../engine/matrix4.h"
#include "../engine/shape.h"

class Block
{
protected:
    Shape shape;
    // Vector3 prevPos;
    // Vector3 currPos;
    // Vector3 prevRot;
    // Vector3 currRot;
    // Vector3 prevScale;
    // Vector3 currScale;
public:
    BlockType type;
    Vector4 color{1.0f, 1.0f, 1.0f, 1.0f};

    Vector3 getPosition() { return shape.transform.getTranslation(); }
    Vector3 getScale() { return shape.transform.getScale(); }

    int xIndex = 0;
    int yIndex = 0;

    Block() = default;
    ~Block() = default;

    virtual void Instantiate(Matrix4 projection,
                             Matrix4 view,
                             Vector3 position = Vector3::zero,
                             Vector3 rotation = Vector3::zero,
                             Vector3 scale = Vector3::one);
    virtual void Destroy();
    virtual void Update(Vector3 position = Vector3::zero,
                        Vector3 rotation = Vector3::zero,
                        Vector3 scale = Vector3::one);
    virtual void Rotate(Vector3 rotation);
    virtual void UpdateView(Matrix4 view);
    virtual void Render(Shader &shader);
};

#endif