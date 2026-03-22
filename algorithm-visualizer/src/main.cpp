#include "app/Application.hpp"

int main() {
    av::Application app;
    const av::Result initResult = app.initialize();
    if (!initResult.isOk()) {
        return 1;
    }

    app.run();
    return 0;
}
