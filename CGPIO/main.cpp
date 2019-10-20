//  Copyright © 2019 Shinernd. All rights reserved.

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define numVAOs 1

GLuint renderingProgram;
GLuint vao[numVAOs];

float x = 0.0f;
float inc = 1.0f;
float size[5];

using namespace std;

GLuint createShaderProgram() {
    const char* vshaderSource =
    "#version 410 \n"
    "void main(void) \n"
    "{gl_Position = vec4(0.0, 0.0, 0.0, 1.0);}";
    const char* fshaderSource =
    "#version 410 \n"
    "out vec4 color; \n"
    "void main(void) \n"
    "{color = vec4(0.0, 0.0, 1.0, 1.0);}";
    
    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
    
    glShaderSource(vShader, 1, &vshaderSource, nullptr);
    glShaderSource(fShader, 1, &fshaderSource, nullptr);
    glCompileShader(vShader);
    glCompileShader(fShader);
    
    GLuint vfProgram = glCreateProgram();

    glAttachShader(vfProgram, vShader);
    glAttachShader(vfProgram, fShader);
    
    glLinkProgram(vfProgram);
    
    return vfProgram;
}


void init (GLFWwindow* window) {
    renderingProgram = createShaderProgram();
    glGenVertexArrays(numVAOs, vao);
    glBindVertexArray(vao[0]);
}

void display(GLFWwindow* window, double currentTime) {
    glUseProgram(renderingProgram);
    
    // Don't forget to clear!!
    glClear(GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    x += inc;
    if (x == 100.0f) inc = -1.0f;
    if (x == 0.0f) inc = 1.0f;
    cout << x << endl;
    
    glPointSize(x);
    glDrawArrays(GL_POINTS, 0, 1);
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
