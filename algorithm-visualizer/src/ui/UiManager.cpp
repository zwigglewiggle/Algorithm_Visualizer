#include "ui/UiManager.hpp"

#include <algorithm>

namespace av {
void UiManager::playPause(AppState& state, PlaybackController& playback) const {
    if (playback.state() == PlaybackState::Playing) {
        playback.pause();
        state.setPlaybackState(PlaybackState::Paused);
    } else {
        playback.play();
        state.setPlaybackState(PlaybackState::Playing);
    }
}

void UiManager::stepForward(AppState& state, PlaybackController& playback) const {
    playback.stepForward();
    state.setCurrentStep(playback.currentIndex());
}

void UiManager::reset(AppState& state, PlaybackController& playback) const {
    playback.reset();
    state.resetPlaybackState();
}

void UiManager::randomize(AppState& state) const {
    state.setRegenerateRequested(true);
}

void UiManager::increaseSpeed(AppState& state, PlaybackController& playback) const {
    state.setPlaybackSpeed(std::min(AppState::kMaxPlaybackSpeed, state.getPlaybackSpeed() + 0.5f));
    playback.setSpeed(state.getPlaybackSpeed());
}

void UiManager::decreaseSpeed(AppState& state, PlaybackController& playback) const {
    state.setPlaybackSpeed(std::max(AppState::kMinPlaybackSpeed, state.getPlaybackSpeed() - 0.5f));
    playback.setSpeed(state.getPlaybackSpeed());
}
} // namespace av
