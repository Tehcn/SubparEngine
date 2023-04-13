#include "engine.h"

#include <iostream>
#include <glm/glm.hpp>
// using namespace glm;

#include "../render/renderers.h"
#include "../common.h"

Engine::Engine(const char* title, int width, int height) {
    glewExperimental = true;
    if(!glfwInit()) {
        ERRORNR("Failed to initialize GLFW");
    }

    m_window = new Window(title, width, height);

    glewExperimental = true;
    if(glewInit() != GLEW_OK) {
        ERRORNR("Failed to initialze GLEW");
    }

    glfwSetInputMode(m_window->glwindow(), GLFW_STICKY_KEYS, GL_TRUE);
}

void Engine::start() {
    // create render thread
    int rrc = pthread_create(&threads[0], nullptr, _render, this);
    utils::log_info("started render thread");
    rrc = pthread_detach(threads[0]);
}

Window* Engine::window() const {
    return m_window;
}

GLFWwindow* Engine::glwindow() const {
    return window()->glwindow();
}

float Engine::fps() const {
    return m_fps;
}

float Engine::dt() const {
    return m_dt;
}

void* _render(void* args) {
    args = (Engine*)args;
    ((Engine*)args)->render();
    return nullptr;
}

void Engine::render() {
    m_window->render();
}

bool Engine::should_close() {
    return m_window->should_close();
}