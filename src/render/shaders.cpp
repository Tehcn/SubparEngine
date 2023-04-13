#include "shaders.h"

GLuint load_shaders(const char* vertex_file_path, const char* fragment_file_path) {
    GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vertexShaderCode = utils::read_file(vertex_file_path);
    std::string fragmentShaderCode = utils::read_file(fragment_file_path);

    utils::log_info("simple.vsh:%s\nsimple.fsh:%s\n");

    GLint result = GL_FALSE;
    int infoLogLength;

    // compile vertex shader (also, this is the first comment im writing lmao)
    utils::log_info("compiling shader: %s\n", vertex_file_path);
    const char* vertexSourcePointer = vertexShaderCode.c_str();
    glShaderSource(vertexShaderId, 1, &vertexSourcePointer, nullptr);
    glCompileShader(vertexShaderId);

    // check compilation status
    glGetShaderiv(vertexShaderId, GL_COMPILE, &result);
    glGetShaderiv(vertexShaderId, GL_INFO_LOG_LENGTH, &infoLogLength);
    if(infoLogLength > 0) {
        std::vector<char> vertexShaderErrorMessage(infoLogLength + 1);
        glGetShaderInfoLog(vertexShaderId, infoLogLength, nullptr, &vertexShaderErrorMessage[0]);
        utils::log_error("Failed to compile vertex shader: %s\n", vertexShaderErrorMessage);
    }

    utils::log_info("compiling shader: %s\n", fragment_file_path);
    const char* fragmentSourcePointer = fragmentShaderCode.c_str();
    glShaderSource(fragmentShaderId, 1, &fragmentSourcePointer, nullptr);
    glCompileShader(fragmentShaderId);

    // check compilation status
    glGetShaderiv(fragmentShaderId, GL_COMPILE, &result);
    glGetShaderiv(fragmentShaderId, GL_INFO_LOG_LENGTH, &infoLogLength);
    if(infoLogLength > 0) {
        std::vector<char> fragmentShaderErrorMessage(infoLogLength + 1);
        glGetShaderInfoLog(fragmentShaderId, infoLogLength, nullptr, &fragmentShaderErrorMessage[0]);
        utils::log_error("failed to compile fragment shader: %s\n", fragmentShaderErrorMessage);
    }

    // link the program
    utils::log_info("linking program\n");
    GLuint programId = glCreateProgram();
    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);
    glLinkProgram(programId);

    // check the program
    glGetProgramiv(programId, GL_LINK_STATUS, &result);
    glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLogLength);
    if(infoLogLength > 0) {
        std::vector<char> programErrorMessage(infoLogLength + 1);
        glGetProgramInfoLog(programId, infoLogLength, nullptr, &programErrorMessage[0]);
        utils::log_error("failed to link program: %s\n", programErrorMessage);
    }

    glDetachShader(programId, vertexShaderId);
    glDetachShader(programId, fragmentShaderId);

    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);

    return programId;
}