#include "rendering/Renderer.hpp"

#include <ostream>

namespace av {
void Renderer::render(std::ostream& stream, const PlaybackController& playback) const {
    const auto* step = playback.currentStep();
    stream << "=== Algorithm Visualizer ===\n";
    stream << "Step: " << playback.currentIndex() << '/' << (playback.timeline().size() == 0 ? 0 : playback.timeline().size() - 1) << "\n";
    stream << "Comparisons: " << playback.metrics().comparisons
           << ", Swaps: " << playback.metrics().swaps
           << ", Writes: " << playback.metrics().writes
           << ", Sorted Marks: " << playback.metrics().sortedMarks << "\n\n";
    stream << m_arrayView.buildFrame(step) << "\n";
}
} // namespace av
