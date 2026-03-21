#include "app/Application.hpp"

using namespace av;
int main() {
    Application app;
    Result initResult = app.initialize();
    if (!initResult.isOk()) {
        return 1;
    }

    app.run();

    return 0;
}
