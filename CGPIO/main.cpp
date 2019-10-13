//  Copyright © 2019 Shinernd. All rights reserved.

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define numVAOs 1

// GLuint : unsigned int
GLuint renderingProgram;
GLuint vao[numVAOs];

using namespace std;

GLuint createShaderProgram() {
    
    // declares two shaders as character strings
    const char* vshaderSource =
    "#version 410 \n"
    "void main(void) \n"
    // sets a vertex's coordinate position in 3D space
    // origin location : (0,0,0)
    "{gl_Position = vec4(0.0, 0.0, 0.0, 1.0);}";
    const char* fshaderSource =
    "#version 430 \n"
    "out vec4 color; \n"
    "void main(void) \n"
    "{color = vec4(0.0, 0.0, 1.0, 1.0);}";
    
    // glCreateShader : generates the two shaders of types GL_VERTEX_SHADER and GL_FRAGMENT_SHADER
    // OpenGL creates each shader object, and returns an integer ID for each
    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
    
    // loads the GLSL code from the strings into the empty shader objects
    // glShaderSource(ShaderObject, NumberOfStrings : 1, ArrayOfPointers, -)
    glShaderSource(vShader, 1, &vshaderSource, nullptr);
    glShaderSource(fShader, 1, &fshaderSource, nullptr);
    
    // the shaders are each compiled
    glCompileShader(vShader);
    glCompileShader(fShader);
    
    // the integer ID of a program object
    GLuint vfProgram = glCreateProgram();
    
    // attatches each of the shaders to the program object
    glAttachShader(vfProgram, vShader);
    glAttachShader(vfProgram, fShader);
    
    // requests that the GLSL compiler ensure that the shaders are compatible
    glLinkProgram(vfProgram);
    
    return vfProgram;
}


void init (GLFWwindow* window) {
    renderingProgram = createShaderProgram();
    
    // VAO : Vertex Array Objects, OpenGL requires at least one VAO
    glGenVertexArrays(numVAOs, vao);
    glBindVertexArray(vao[0]);
}

void display(GLFWwindow* window, double currentTime) {
    
    // loads the program containing the two compiled shaders into the OpenGL pipeline stages (onto the GPU)
    glUseProgram(renderingProgram);
    
    glPointSize(30.0f);
    
    // initiates pipeline processing
    // mode: GL_POINTS, from 0, one (point)
    glDrawArrays(GL_POINT, 0, 1);
}

int main(void) {
    if (!glfwInit()) {exit(EXIT_FAILURE);}
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // I don't know what this does
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // and neither this
    GLFWwindow* window = glfwCreateWindow(600, 600, "Chapter2 - program2", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {exit(EXIT_FAILURE);}                // without the line 80 or 81, this makes an error
    glfwSwapInterval(1);
    
    init(window);
    
    while (!glfwWindowShouldClose(window)) {
        display(window, glfwGetTime());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
