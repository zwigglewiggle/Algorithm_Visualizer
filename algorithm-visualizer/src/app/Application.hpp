#pragma once

#include "app/AppState.hpp"
#include "core/Result.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

class Renderer;
class UiManager;
class PlaybackController;

class Application
{
public:
    Application();
    ~Application();

    av::Result initialize();
    void run();

    void update(float deltaTimeSeconds);
    void render();
    void processEvents();

    bool isInitialized() const;

    AppState& getState();
    const AppState& getState() const;

private:
    av::Result createWindow();
    void initializeState();
    void shutdown();

private:
    sf::RenderWindow m_window;
    AppState m_state;
    bool m_initialized = false;
    bool m_running = false;
    float m_lastDeltaTimeSeconds = 0.0f;
    sf::Clock m_frameClock;

};