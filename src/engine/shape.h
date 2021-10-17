#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glew.h>
#include "shader.h"
#include "vector4.h"

class Shape
{
private:
    GLfloat vertices[108]{
        -0.25f, 0.25f, -0.25f,
        -0.25f, -0.25f, -0.25f,
        0.25f, -0.25f, -0.25f,

        0.25f, -0.25f, -0.25f,
        0.25f, 0.25f, -0.25f,
        -0.25f, 0.25f, -0.25f,

        0.25f, -0.25f, -0.25f,
        0.25f, -0.25f, 0.25f,
        0.25f, 0.25f, -0.25f,

        0.25f, -0.25f, 0.25f,
        0.25f, 0.25f, 0.25f,
        0.25f, 0.25f, -0.25f,

        0.25f, -0.25f, 0.25f,
        -0.25f, -0.25f, 0.25f,
        0.25f, 0.25f, 0.25f,

        -0.25f, -0.25f, 0.25f,
        -0.25f, 0.25f, 0.25f,
        0.25f, 0.25f, 0.25f,

        -0.25f, -0.25f, 0.25f,
        -0.25f, -0.25f, -0.25f,
        -0.25f, 0.25f, 0.25f,

        -0.25f, -0.25f, -0.25f,
        -0.25f, 0.25f, -0.25f,
        -0.25f, 0.25f, 0.25f,

        -0.25f, -0.25f, 0.25f,
        0.25f, -0.25f, 0.25f,
        0.25f, -0.25f, -0.25f,

        0.25f, -0.25f, -0.25f,
        -0.25f, -0.25f, -0.25f,
        -0.25f, -0.25f, 0.25f,

        -0.25f, 0.25f, -0.25f,
        0.25f, 0.25f, -0.25f,
        0.25f, 0.25f, 0.25f,

        0.25f, 0.25f, 0.25f,
        -0.25f, 0.25f, 0.25f,
        -0.25f, 0.25f, -0.25f};

    GLuint vao;
    GLuint buffer;

public:
    Matrix4 transform;
    Matrix4 projection;
    Matrix4 view;
    Vector4 color{Vector4(1.0f, 1.0f, 1.0f, 1.0f)};

    Shape() = default;
    void CreateShape();
    void Transform(Vector3 position, Vector3 rotation, Vector3 scale);
    void Rotate(Vector3 rotation);
    void Draw(Shader &shader);
    void Clean();
};

#endif