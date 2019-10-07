//  Copyright © 2019 Shinernd. All rights reserved.

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

void init (GLFWwindow* window) {}

void display(GLFWwindow* window, double currentTime) {
    glClearColor(1.0, 0.0, 0.0, 1.0);
    
    // void glClear(GLbitfield mask)
    // GL_COLOR_BUFFERE_BIT : references the color buffer
    // glClear() : clears all of color buffers that OpenGL has
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(void) {
    if (!glfwInit()) {exit(EXIT_FAILURE);}
    
    // OpenGL version 2.0
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    
    // monitor, share: for full screen moce and resource sharing
    GLFWwindow* window = glfwCreateWindow(600, 600, "Chapter2 - program1", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {exit(EXIT_FAILURE);}
    
    // vertical synchronization (VSyc)
    glfwSwapInterval(1);
    
    // includes a reference to the GLFW window object
    init(window);
    
    // rendering loop
    // glfwWindowShouldClose : makes the loop terminate when GLFW detects an sould-close event
    while (!glfwWindowShouldClose(window)) {
        
        // includes a reference to the GLFW windows object and the current time
        display(window, glfwGetTime());
        
        // vertical synchronization (VSyc)
        // paints the screen
        glfwSwapBuffers(window);
        
        // handles other window-related events
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
