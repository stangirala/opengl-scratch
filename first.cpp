#include <iostream>

// Includes openGL and other constants.
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <glm/glm.hpp>

int main(int argc, char **argv)
{
    if (!glfwInit())
    {
        std::cerr << "GLFW not initialized." << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

    return 0;
}
