#include "./App.h"

App::App()
{
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}


void HandleResize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void App::run()
{
    while(!glfwWindowShouldClose(Window))
    {
        // Update Input
        glfwPollEvents();

        // Update

        // Darw

        // Clear
        glClearColor(0.06f, 0.07f, 0.14f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw

        // End of Draw
        glfwSwapBuffers(Window);
        glFlush();
    }
}

void App::createWindow()
{
    Window = glfwCreateWindow(WindowWidth, WindowHeight, WindowTitle.c_str(), NULL, NULL);
    if(Window == NULL)
    {
        std::cout << "Failed to create Window" << std::endl;
    }
    glfwMakeContextCurrent(Window);
    glfwSetFramebufferSizeCallback(Window, HandleResize);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        exit(EXIT_FAILURE);
    }

}

void App::createWindow(int width, int height)
{
    WindowWidth = width;
    WindowHeight = height;
    createWindow();
}

void App::createWindow(int width, int height, const std::string title)
{
    WindowWidth = width;
    WindowHeight = height;
    WindowTitle = title;
    createWindow();
}

void App::AddShader(const std::string shaderLocation, GLenum shaderType)
{
    unsigned int shader = glCreateShader(shaderType);
    if(shaderType == GL_VERTEX_SHADER)
        vertex_shader = shader;
    else if(shaderType == GL_FRAGMENT_SHADER)
        fragment_shader = shader;

    std::string ShaderStream;
    std::ifstream shaderFile(shaderLocation);
    if(shaderFile.is_open())
    {
        std::stringstream sstream;
        sstream << shaderFile.rdbuf();
        ShaderStream = sstream.str();
        shaderFile.close();
    }
    else
    {
        std::cout << "Unable to open shader file" << std::endl;
        return;
    }

    const char* ShaderCode = ShaderStream.c_str();

    glShaderSource(shader, 1, &ShaderCode, NULL);
    glCompileShader(shader);

    glAttachShader(shader_program, shader);
}

void App::LinkProgram()
{
    glLinkProgram(shader_program);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

App::~App()
{
    glfwTerminate();
}
