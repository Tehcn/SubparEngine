#include "window.h"

#include <iostream>

#include "../common.h"
#include "../render/shaders.h"

Window::Window(const char* title, int width, int height) : m_title(title), m_width(width), m_height(height) {
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* win = glfwCreateWindow(1024, 768, "SubparEngine", nullptr, nullptr);
    if(win == nullptr) ERRORCNR("Failed to initialize GLFW window", glfwTerminate);
    else m_window = win;
    glfwMakeContextCurrent(m_window);
}

Window::~Window() {
    glfwTerminate();
    m_window = nullptr;
    m_title = nullptr;
}

const char* Window::title() const {
    return m_title;
}

int Window::width() const {
    return m_width;
}

int Window::height() const {
    return m_height;
}

GLFWwindow* Window::glwindow() const {
    return m_window;
}

void Window::render() {
    GLFWwindow* win = m_window;
    
    GLuint programId = load_shaders("shaders/simple.vsh", "shaders/simple.fsh");

    do {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(programId);
        for(int i=0;i<render_functions.size();i++) {
            render_functions.at(i)();
        }

        // Swap buffers
        glfwSwapBuffers(win);
        glfwPollEvents();
    } while(glfwGetKey(win, GLFW_KEY_ESCAPE) != GLFW_PRESS && should_close() == 0);
}

int Window::should_close() { return glfwWindowShouldClose(m_window); }

void Window::add_render_function(std::function<void()> render_function) {
    render_functions.push_back(render_function);
}