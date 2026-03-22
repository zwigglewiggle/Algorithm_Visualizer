#pragma once

#include "algorithms/common/Algorithm.hpp"
#include "core/Types.hpp"
#include "playback/Timeline.hpp"

namespace av {
class PlaybackController {
public:
    void load(const AlgorithmResult& result);
    void clear();

    void setSpeed(float speed);
    float speed() const;

    void play();
    void pause();
    void reset();
    void stepForward();
    void update(float deltaTimeSeconds);

    PlaybackState state() const;
    StepIndex currentIndex() const;
    const AlgorithmStep* currentStep() const;
    const Timeline& timeline() const;
    const Metrics& metrics() const;

private:
    Timeline m_timeline{};
    StepIndex m_currentIndex{0};
    PlaybackState m_state{PlaybackState::Idle};
    float m_speed{1.0f};
    float m_accumulator{0.0f};
    Metrics m_metrics{};
};
} // namespace av
