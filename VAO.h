#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include <glad/glad.h>

class VAO
{
public:
    GLuint ID;
    VAO()
    {
        glGenVertexArrays(1, &ID);
    }

    void Bind()
    {
        glBindVertexArray(ID);
    }

    void Unbind()
    {
        glBindVertexArray(0);
    }

    void Delete()
    {
        glDeleteVertexArrays(1, &ID);
    }

    void LinkAttrib(GLuint VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
    {
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
        glEnableVertexAttribArray(layout);
    }
};

#endif

