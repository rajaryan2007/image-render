#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

#include <glad/glad.h>

// Function to read shader source code from file
std::string get_file_contents(const char* filename)
{
    std::ifstream in(filename, std::ios::in | std::ios::binary);
    if (in)
    {
        std::ostringstream contents;
        contents << in.rdbuf();
        in.close();
        return contents.str();
    }
    throw(errno);
}

// Shader class
class Shader
{
public:
    GLuint ID;

    // Constructor generates the shader program from 2 files
    Shader(const char* vertexFile, const char* fragmentFile)
    {
        std::string vertexCode = get_file_contents(vertexFile);
        std::string fragmentCode = get_file_contents(fragmentFile);

        const char* vertexSource = vertexCode.c_str();
        const char* fragmentSource = fragmentCode.c_str();

        // Create Vertex Shader
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexSource, NULL);
        glCompileShader(vertexShader);
        checkCompileErrors(vertexShader, "VERTEX");

        // Create Fragment Shader
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
        glCompileShader(fragmentShader);
        checkCompileErrors(fragmentShader, "FRAGMENT");

        // Create Shader Program
        ID = glCreateProgram();
        glAttachShader(ID, vertexShader);
        glAttachShader(ID, fragmentShader);
        glLinkProgram(ID);
        checkCompileErrors(ID, "PROGRAM");

        // Delete the shaders as they're now linked
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    // Activate the shader program
    void Activate()
    {
        glUseProgram(ID);
    }

    // Delete the shader program
    void Delete()
    {
        glDeleteProgram(ID);
    }

private:
    // Utility function to check for shader compilation/linking errors.
    void checkCompileErrors(GLuint shader, std::string type)
    {
        GLint success;
        GLchar infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: "
                    << type << "\n" << infoLog << "\n";
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cerr << "ERROR::PROGRAM_LINKING_ERROR of type: "
                    << type << "\n" << infoLog << "\n";
            }
        }
    }
};

#endif
