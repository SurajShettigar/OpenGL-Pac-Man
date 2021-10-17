#ifndef SHADER_H
#define SHADER_H
 
#include <GL/glew.h>
#include "log.h"
#include "vector2.h"
#include "vector3.h"
#include "vector4.h"
#include "matrix4.h"

class Shader
{
public:
    Shader();
    virtual ~Shader();
 
    GLuint programId;

    void compileVertexShader();
    void compileFragmentShader();
    void createShaderProgram();

 	// Sets the current shader as active
	Shader& use();

    // Utility functions
	void setFloat(const GLchar *name, GLfloat value);
	void setInteger(const GLchar *name, GLint value);
	void setVector2f(const GLchar *name, GLfloat x, GLfloat y);
	void setVector2f(const GLchar *name, const Vector2 &value);
	void setVector3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z);
	void setVector3f(const GLchar *name, const Vector3 &value);
	void setVector4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void setVector4f(const GLchar *name, const Vector4 &value);
	void setMatrix4(const GLchar *name, const Matrix4 &matrix);
	//void setMatrix4Row(const GLchar *name, const Matrix4Row &matrix);
 
private:
    GLuint vs;
    GLuint fs;
 
    const char* vertexShader =
        "#version 430\n"
        "in vec4 position;"

        // "out VS_OUT"
        // "{"
        //     "vec4 color;"
        // "} vs_out;"

        "uniform mat4 mv_matrix;"
        "uniform mat4 view_matrix;"
        "uniform mat4 proj_matrix;"

        "void main(void)"
        "{"
            "gl_Position = proj_matrix * view_matrix * mv_matrix * position;"
            // "vs_out.color = position * 2.0 + vec4(0.5, 0.5, 0.5, 0.0);"
        "}";


    const char* fragmentShader =
        "#version 430\n"

        "out vec4 color;"

        // "in VS_OUT"
        // "{"
        //     "vec4 color;"
        // "} fs_in;"

        "uniform vec4 baseColor;"

        "void main()"
        "{"
            "color = baseColor;"
        "}";
 
    void checkShaderErrors(GLuint shader, std::string shaderType);

    void printShaderInfoLog(GLuint shaderIndex);
    void printProgramInfoLog(GLuint programId);
    const char *GLTypeToString(GLenum type);
    void printAllParams(GLuint programId);
    bool isValid(GLuint programId);
 
    Shader(const Shader &) = delete;
    Shader& operator=(const Shader &) = delete;
};
 
#endif