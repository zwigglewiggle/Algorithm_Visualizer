#pragma once

#include "app/AppState.hpp"
#include "playback/PlaybackController.hpp"

namespace av {
class UiManager {
public:
    void playPause(AppState& state, PlaybackController& playback) const;
    void stepForward(AppState& state, PlaybackController& playback) const;
    void reset(AppState& state, PlaybackController& playback) const;
    void randomize(AppState& state) const;
    void increaseSpeed(AppState& state, PlaybackController& playback) const;
    void decreaseSpeed(AppState& state, PlaybackController& playback) const;
};
} // namespace av
