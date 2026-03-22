#include "app/AppState.hpp"

using namespace av;

AppState::AppState() {
    m_selectedAlgorithm = AlgorithmType::BubbleSort;
    m_playbackState = PlaybackState::Idle;
    m_datasetSize = 50;
    m_playbackSpeed = 1.0f;
    m_currentStep = 0;
    m_presetType = DataPresetType::Random;
    m_regenerateRequested = true;
}

AlgorithmType AppState::getSelectedAlgorithm() const { return m_selectedAlgorithm; }
PlaybackState AppState::getPlaybackState() const { return m_playbackState; }
std::size_t AppState::getDatasetSize() const { return m_datasetSize; }
float AppState::getPlaybackSpeed() const { return m_playbackSpeed; }
StepIndex AppState::getCurrentStep() const { return m_currentStep; }
DataPresetType AppState::getPresetType() const { return m_presetType; }

Result AppState::setSelectedAlgorithm(AlgorithmType algorithm) {
    if (algorithm == AlgorithmType::Unknown) {
        return Result::failure(StatusCode::InvalidArgument, "unknown algorithm");
    }
    m_selectedAlgorithm = algorithm;
    resetPlaybackState();
    return Result::success();
}

void AppState::setPlaybackState(PlaybackState state) { m_playbackState = state; }

Result AppState::setDatasetSize(std::size_t size) {
    if (size < kMinDatasetSize || size > kMaxDatasetSize) {
        return Result::failure(StatusCode::InvalidArgument, "dataset size out of range");
    }
    m_datasetSize = size;
    m_regenerateRequested = true;
    resetPlaybackState();
    return Result::success();
}

Result AppState::setPlaybackSpeed(float speed) {
    if (speed < kMinPlaybackSpeed || speed > kMaxPlaybackSpeed) {
        return Result::failure(StatusCode::InvalidArgument, "playback speed out of range");
    }
    m_playbackSpeed = speed;
    return Result::success();
}

Result AppState::setCurrentStep(StepIndex step) {
    m_currentStep = step;
    return Result::success();
}

Result AppState::setPresetType(DataPresetType preset) {
    m_presetType = preset;
    m_regenerateRequested = true;
    resetPlaybackState();
    return Result::success();
}

void AppState::setRegenerateRequested(bool regenerate) { m_regenerateRequested = regenerate; }
bool AppState::isRegenerateRequested() const { return m_regenerateRequested; }

void AppState::resetPlaybackState() {
    m_playbackState = PlaybackState::Idle;
    m_currentStep = 0;
}

Result AppState::validate() const {
    if (m_selectedAlgorithm == AlgorithmType::Unknown) {
        return Result::failure(StatusCode::InvalidArgument, "unknown algorithm");
    }
    if (m_datasetSize < kMinDatasetSize || m_datasetSize > kMaxDatasetSize) {
        return Result::failure(StatusCode::InvalidArgument, "dataset size invalid");
    }
    if (m_playbackSpeed < kMinPlaybackSpeed || m_playbackSpeed > kMaxPlaybackSpeed) {
        return Result::failure(StatusCode::InvalidArgument, "playback speed invalid");
    }
    return Result::success();
}
