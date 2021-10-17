#include "block.h"

void Block::Instantiate(Matrix4 projection,
                        Matrix4 view,
                        Vector3 position,
                        Vector3 rotation,
                        Vector3 scale)
{
    shape.color = color;
    shape.CreateShape();
    shape.projection = projection;
    shape.view = view;
    shape.Transform(position, rotation, scale);
}

void Block::Update(Vector3 position,
                   Vector3 rotation,
                   Vector3 scale)
{
    shape.Transform(position, rotation, scale);
}

void Block::Rotate(Vector3 rotation)
{
    shape.Rotate(rotation);
}

void Block::UpdateView(Matrix4 view)
{
    shape.view = view;
}

void Block::Render(Shader& shader)
{
    shape.Draw(shader);
}

void Block::Destroy()
{
    shape.Clean();
}
