#ifndef SE_ENGINE_H
#define SE_ENGINE_H

#include "window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <functional>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <pthread.h>

#ifndef MAX_THREADS
    #define MAX_THREADS 4
#endif

void* _render(void* args);

class Engine {
private:
    Window* m_window;
    float m_fps;
    float m_dt;
    pthread_t threads[MAX_THREADS];
    std::mutex m_mutex;
    std::condition_variable m_cv;
    bool m_running;
public:
    Engine(const char* title, int width, int height);
    ~Engine();

    Window* window() const;
    GLFWwindow* glwindow() const;
    float fps() const;
    float dt() const;
    void start();
    void render();
    bool should_close();
};

#endif