#include <iostream>

#include <GL/glew.h>
// Includes openGL and other constants.
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

void error_callback(int errno, const char *desc)
{
    std::cerr << "Code: " << errno << " Text: " << desc << std::endl;
}

int main(int argc, char **argv)
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
    {
        std::cerr << "GLFW not initialized." << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    // Working with 3.1 for now.
    /*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);*/

    GLFWwindow *window;
    window = glfwCreateWindow(1024, 768, "First", NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "Failed to open window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to initialize glew" << std::endl;
        return -1;
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
           && glfwWindowShouldClose(window) == 0)
    {
        // Simply swap buffers for now.
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
