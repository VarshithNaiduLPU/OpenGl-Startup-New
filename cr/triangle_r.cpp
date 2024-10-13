#include "../src/Application/App.h"
#include "../src/Headers.h"


int main() {
    App app;
    app.createWindow(800, 600, "It may be a game...");

    app.AddShader("./Shaders/vertex.glsl", GL_VERTEX_SHADER);
    app.AddShader("./Shaders/fragment.glsl", GL_FRAGMENT_SHADER);

    app.run();

    return 0;
}
