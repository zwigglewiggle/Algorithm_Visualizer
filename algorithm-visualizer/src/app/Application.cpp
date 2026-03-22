#include "app/Application.hpp"

#include <chrono>
#include <iostream>
#include <thread>

namespace av {
Application::Application() = default;

Result Application::initialize() {
    if (m_initialized) {
        return Result::success("already initialized");
    }

    initializeState();
    rebuildVisualization();
    m_initialized = true;
    return Result::success();
}

void Application::initializeState() {
    m_state = AppState();
    m_playback.setSpeed(m_state.getPlaybackSpeed());
}

void Application::rebuildVisualization() {
    m_dataSet = DataGenerator::generate(m_state.getDatasetSize(), m_state.getPresetType());
    const AlgorithmContext context{};
    const auto result = m_bubbleSort.run(m_dataSet, context);
    m_playback.load(result);
    m_playback.setSpeed(m_state.getPlaybackSpeed());
    m_state.setRegenerateRequested(false);
    m_state.resetPlaybackState();
}

void Application::run() {
    if (!m_initialized) {
        return;
    }

    render();
    std::this_thread::sleep_for(std::chrono::milliseconds(160));

    m_uiManager.playPause(m_state, m_playback);
    for (int tick = 0; tick < 8 && m_playback.state() != PlaybackState::Finished; ++tick) {
        update(0.25f);
        render();
        std::this_thread::sleep_for(std::chrono::milliseconds(220));
    }

    m_uiManager.reset(m_state, m_playback);
    render();
}

void Application::update(float deltaTimeSeconds) {
    if (m_state.isRegenerateRequested()) {
        rebuildVisualization();
    }

    m_playback.update(deltaTimeSeconds);
    m_state.setCurrentStep(m_playback.currentIndex());
    m_state.setPlaybackState(m_playback.state());
}

void Application::render() {
    m_renderer.render(std::cout, m_playback);
}

bool Application::isInitialized() const { return m_initialized; }
AppState& Application::getState() { return m_state; }
const AppState& Application::getState() const { return m_state; }
} // namespace av
