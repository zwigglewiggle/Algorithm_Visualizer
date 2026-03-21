#include "app/Application.hpp"

int main() {
    Application app;
    Result initResult = app.initialize();
    if (!initResult.isSuccess()) {
        return -1;
    }

    app.run();

    return 0;
}
