#include "rendering/views/ArrayView.hpp"

#include <algorithm>
#include <sstream>

namespace av {
std::string ArrayView::buildFrame(const AlgorithmStep* step, std::size_t maxBars) const {
    if (step == nullptr || step->snapshot.empty()) {
        return "[no data]";
    }

    const std::size_t visibleBars = std::min(maxBars, step->snapshot.size());
    const auto maxValue = *std::max_element(step->snapshot.begin(), step->snapshot.end());
    std::ostringstream output;

    for (std::size_t i = 0; i < visibleBars; ++i) {
        const auto value = step->snapshot[i];
        const std::size_t width = maxValue == 0 ? 0 : static_cast<std::size_t>((40.0 * value) / maxValue);
        char marker = '#';
        if (step->sortedMask.size() == step->snapshot.size() && step->sortedMask[i]) {
            marker = 'S';
        }
        if (step->indices[0] == i || step->indices[1] == i) {
            marker = (step->type == StepType::Compare) ? 'C' : 'X';
        }
        output << i << ':' << std::string(std::max<std::size_t>(1, width), marker) << " (" << value << ")\n";
    }

    if (step->snapshot.size() > visibleBars) {
        output << "... (" << (step->snapshot.size() - visibleBars) << " weitere Werte)";
    }

    return output.str();
}
} // namespace av
