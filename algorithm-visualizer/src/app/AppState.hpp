#pragma once

#include "core/Result.hpp"
#include "core/Types.hpp"
#include "data/Presets.hpp"

class AppState {
public:
    static constexpr std::size_t kMinDatasetSize = 5;
    static constexpr std::size_t kMaxDatasetSize = 500;
    static constexpr float kMinPlaybackSpeed = 0.1f;
    static constexpr float kMaxPlaybackSpeed = 10.0f;

    AppState();

    av::AlgorithmType getSelectedAlgorithm() const;
    av::Result setSelectedAlgorithm(av::AlgorithmType algorithm);
    av::PlaybackState getPlaybackState() const;
    void setPlaybackState(av::PlaybackState state);
    std::size_t getDatasetSize() const;
    av::Result setDatasetSize(std::size_t size);
    float getPlaybackSpeed() const;
    av::Result setPlaybackSpeed(float speed);
    av::StepIndex getCurrentStep() const;
    av::Result setCurrentStep(av::StepIndex step);
    av::DataPresetType getPresetType() const;
    av::Result setPresetType(av::DataPresetType preset);
    bool isRegenerateRequested() const;
    void setRegenerateRequested(bool regenerate);
    void resetPlaybackState();
    av::Result validate() const;

private:
    av::AlgorithmType m_selectedAlgorithm{};
    av::PlaybackState m_playbackState{};
    std::size_t m_datasetSize{};
    float m_playbackSpeed{};
    av::StepIndex m_currentStep{};
    av::DataPresetType m_presetType{};
    bool m_regenerateRequested{};
};
