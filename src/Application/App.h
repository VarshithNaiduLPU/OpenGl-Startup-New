#include "../Headers.h"

class App {
private:
    GLFWwindow * Window;

    int WindowWidth = 800;
    int WindowHeight = 600;
    std::string WindowTitle = "OpenGL";

    int FrameBufferWidth = 0;
    int FrameBufferHeight = 0;

    unsigned int shader_program = NULL, vertex_shader = NULL, fragment_shader = NULL;


public:
    App();
    ~App();

    void run();
    void createWindow();
    void createWindow(int width, int height);
    void createWindow(int width, int height, const std::string title);
    void App::AddShader(const std::string shaderLocation, GLenum shaderType);
    void App::LinkProgram();
};
