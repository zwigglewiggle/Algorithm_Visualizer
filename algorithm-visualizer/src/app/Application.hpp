#pragma once

#include "algorithms/common/Algorithm.hpp"
#include "algorithms/common/DataSet.hpp"
#include "algorithms/sorting/BubbleSort.hpp"
#include "app/AppState.hpp"
#include "core/Result.hpp"
#include "data/DataGenerator.hpp"
#include "playback/PlaybackController.hpp"
#include "rendering/Renderer.hpp"
#include "ui/UiManager.hpp"

namespace av {
class Application {
public:
    Application();

    Result initialize();
    void run();

    bool isInitialized() const;
    AppState& getState();
    const AppState& getState() const;

private:
    void initializeState();
    void update(float deltaTimeSeconds);
    void render();
    void rebuildVisualization();

    AppState m_state{};
    Renderer m_renderer{};
    UiManager m_uiManager{};
    PlaybackController m_playback{};
    DataSet m_dataSet{};
    BubbleSort m_bubbleSort{};
    bool m_initialized{false};
};
} // namespace av
