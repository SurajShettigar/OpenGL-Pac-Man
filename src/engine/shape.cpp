#include "shape.h"

#include <GL/glew.h>

void Shape::CreateShape()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);
}

void Shape::Transform(Vector3 position, Vector3 rotation, Vector3 scale) {

    Matrix4 s =  Matrix4::createScale(scale);

    Matrix4 rX =  Matrix4::createRotationX(rotation.x);
    Matrix4 rY = Matrix4::createRotationY(rotation.y);
    Matrix4 rZ = Matrix4::createRotationY(rotation.z);
    Matrix4 r =  rY * rX;
    r = rZ * r;

    Matrix4 p =  Matrix4::createTranslation(position);

    transform = r * s;
    transform = p * transform;
}

void Shape::Rotate(Vector3 rotation) {

    Matrix4 rX =  Matrix4::createRotationX(rotation.x);
    Matrix4 rY = Matrix4::createRotationY(rotation.y);
    Matrix4 rZ = Matrix4::createRotationY(rotation.z);
    Matrix4 r =  rY * rX;
    r = rZ * r;
    
    transform = r * transform;
}

void Shape::Draw(Shader &shader) {

    shader.use();
    shader.setMatrix4("mv_matrix", transform);
    shader.setMatrix4("view_matrix", view);
    shader.setMatrix4("proj_matrix", projection);
    shader.setVector4f("baseColor", color);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Shape::Clean()
{
    glDeleteVertexArrays(1, &vao);
}
