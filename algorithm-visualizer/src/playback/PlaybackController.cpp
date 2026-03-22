#include "playback/PlaybackController.hpp"

namespace av {
void PlaybackController::load(const AlgorithmResult& result) {
    m_timeline.setSteps(result.steps);
    m_metrics = result.metrics;
    reset();
}

void PlaybackController::clear() {
    m_timeline.clear();
    m_currentIndex = 0;
    m_state = PlaybackState::Idle;
    m_accumulator = 0.0f;
    m_metrics.reset();
}

void PlaybackController::setSpeed(float speed) {
    m_speed = speed;
}

float PlaybackController::speed() const {
    return m_speed;
}

void PlaybackController::play() {
    if (!m_timeline.empty()) {
        m_state = PlaybackState::Playing;
    }
}

void PlaybackController::pause() {
    if (m_state == PlaybackState::Playing) {
        m_state = PlaybackState::Paused;
    }
}

void PlaybackController::reset() {
    m_currentIndex = 0;
    m_accumulator = 0.0f;
    m_state = m_timeline.empty() ? PlaybackState::Idle : PlaybackState::Paused;
}

void PlaybackController::stepForward() {
    if (m_timeline.empty()) {
        return;
    }
    if (m_currentIndex + 1 < m_timeline.size()) {
        ++m_currentIndex;
    } else {
        m_state = PlaybackState::Finished;
    }
}

void PlaybackController::update(float deltaTimeSeconds) {
    if (m_state != PlaybackState::Playing || m_timeline.empty()) {
        return;
    }

    const float secondsPerStep = 1.0f / (m_speed <= 0.0f ? 1.0f : m_speed * 8.0f);
    m_accumulator += deltaTimeSeconds;

    while (m_accumulator >= secondsPerStep && m_state == PlaybackState::Playing) {
        m_accumulator -= secondsPerStep;
        if (m_currentIndex + 1 < m_timeline.size()) {
            ++m_currentIndex;
        } else {
            m_state = PlaybackState::Finished;
        }
    }
}

PlaybackState PlaybackController::state() const {
    return m_state;
}

StepIndex PlaybackController::currentIndex() const {
    return m_currentIndex;
}

const AlgorithmStep* PlaybackController::currentStep() const {
    return m_timeline.tryGet(m_currentIndex);
}

const Timeline& PlaybackController::timeline() const {
    return m_timeline;
}

const Metrics& PlaybackController::metrics() const {
    return m_metrics;
}
} // namespace av
