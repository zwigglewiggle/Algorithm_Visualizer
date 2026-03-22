#include "rendering/views/ArrayView.hpp"

#include <algorithm>
#include <iomanip>
#include <sstream>

namespace av {
namespace {
std::string colorForBar(const AlgorithmStep& step, std::size_t index) {
    constexpr const char* reset = "\033[0m";
    if (step.indices[0] == index || step.indices[1] == index) {
        if (step.type == StepType::Compare) {
            return "\033[38;5;226m";
        }
        if (step.type == StepType::Swap || step.type == StepType::Write) {
            return "\033[38;5;207m";
        }
    }

    if (step.sortedMask.size() == step.snapshot.size() && step.sortedMask[index]) {
        return "\033[38;5;84m";
    }

    return "\033[38;5;81m";
}

char glyphForBar(const AlgorithmStep& step, std::size_t index) {
    if (step.indices[0] == index || step.indices[1] == index) {
        if (step.type == StepType::Compare) {
            return '@';
        }
        if (step.type == StepType::Swap || step.type == StepType::Write) {
            return '%';
        }
    }

    if (step.sortedMask.size() == step.snapshot.size() && step.sortedMask[index]) {
        return '=';
    }

    return '#';
}
} // namespace

std::string ArrayView::buildFrame(const AlgorithmStep* step, std::size_t maxBars) const {
    if (step == nullptr || step->snapshot.empty()) {
        return "[no data]";
    }

    constexpr const char* reset = "\033[0m";
    const std::size_t visibleBars = std::min(maxBars, step->snapshot.size());
    const auto maxValue = *std::max_element(step->snapshot.begin(), step->snapshot.end());
    std::ostringstream output;

    for (std::size_t i = 0; i < visibleBars; ++i) {
        const auto value = step->snapshot[i];
        const std::size_t width = maxValue == 0 ? 0 : static_cast<std::size_t>((28.0 * value) / maxValue);
        const auto color = colorForBar(*step, i);
        const auto glyph = glyphForBar(*step, i);

        output << "  " << std::setw(2) << i << " │ " << color
               << std::string(std::max<std::size_t>(1, width), glyph) << reset
               << "  " << std::setw(3) << value;

        output << '\n';
    }

    if (step->snapshot.size() > visibleBars) {
        output << "  … │ " << (step->snapshot.size() - visibleBars) << " weitere Werte ausgeblendet\n";
    }

    return output.str();
}
} // namespace av
