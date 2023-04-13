#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
using namespace glm;

// #include "engine/window.h"
#include "engine/engine.h"
#include "common.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main() {
    Engine* engine = new Engine("Subpar Games", WINDOW_WIDTH, WINDOW_HEIGHT);
    engine->start();
    
    return 0;
}
