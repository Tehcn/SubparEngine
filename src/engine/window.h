#ifndef SE_WINDOW_H
#define SE_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <functional>
#include <vector>

class Window {
private:
    const char* m_title;
    int m_width;
    int m_height;
    GLFWwindow* m_window;
    std::vector<std::function<void()>> render_functions;
public:
    Window(const char* title, int width, int height);
    ~Window();

    const char* title() const;
    int width() const;
    int height() const;
    GLFWwindow* glwindow() const;
    void render();
    void add_render_function(std::function<void()> render_function);
    int should_close();
};


#endif