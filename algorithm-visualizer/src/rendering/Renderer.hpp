#pragma once

#include "playback/PlaybackController.hpp"
#include "rendering/views/ArrayView.hpp"

#include <iosfwd>

namespace av {
class Renderer {
public:
    void render(std::ostream& stream, const PlaybackController& playback) const;

private:
    ArrayView m_arrayView{};
};
} // namespace av
