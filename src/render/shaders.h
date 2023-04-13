#ifndef SE_SHADERS_H
#define SE_SHADERS_H

#include "../common.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLuint load_shaders(const char* vertex_file_path, const char* fragment_file_path);

#endif