#include "rendering/Renderer.hpp"

#include <iomanip>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

namespace av {
namespace {
constexpr const char* kReset = "\033[0m";
constexpr const char* kPanel = "\033[38;5;250m";
constexpr const char* kTitle = "\033[1;38;5;81m";
constexpr const char* kMuted = "\033[38;5;244m";

std::string repeat(const std::string& value, std::size_t count) {
    std::string out;
    out.reserve(value.size() * count);
    for (std::size_t i = 0; i < count; ++i) {
        out += value;
    }
    return out;
}

std::string padRight(const std::string& text, std::size_t width) {
    if (text.size() >= width) {
        return text.substr(0, width);
    }
    return text + std::string(width - text.size(), ' ');
}

std::string boxedPanel(const std::string& title, const std::vector<std::string>& lines, std::size_t width) {
    std::ostringstream out;
    out << kPanel << "┌" << repeat("─", width - 2) << "┐\n";
    out << "│ " << kTitle << padRight(title, width - 4) << kPanel << " │\n";
    out << "├" << repeat("─", width - 2) << "┤\n";
    for (const auto& line : lines) {
        out << "│ " << padRight(line, width - 4) << " │\n";
    }
    out << "└" << repeat("─", width - 2) << "┘" << kReset;
    return out.str();
}

std::string playbackStateLabel(PlaybackState state) {
    switch (state) {
    case PlaybackState::Idle:
        return "Idle";
    case PlaybackState::Playing:
        return "Playing";
    case PlaybackState::Paused:
        return "Paused";
    case PlaybackState::Finished:
        return "Finished";
    }
    return "Unknown";
}

std::string stepTypeLabel(StepType type) {
    switch (type) {
    case StepType::Compare:
        return "Compare";
    case StepType::Swap:
        return "Swap";
    case StepType::Write:
        return "Write";
    case StepType::MarkSorted:
        return "Mark Sorted";
    case StepType::Done:
        return "Done";
    case StepType::None:
    default:
        return "Init";
    }
}
} // namespace

void Renderer::render(std::ostream& stream, const PlaybackController& playback) const {
    const auto* step = playback.currentStep();
    const auto& currentMetrics = step != nullptr ? step->metrics : playback.metrics();
    const auto totalSteps = playback.timeline().size();
    const auto currentStep = playback.currentIndex();
    const auto progress = totalSteps == 0 ? 0.0 : static_cast<double>(currentStep + 1) / static_cast<double>(totalSteps);
    const std::size_t filled = static_cast<std::size_t>(progress * 24.0);

    stream << "\033[2J\033[H";
    stream << kTitle << "Algorithm Visualizer" << kReset << "  " << kMuted
           << "Terminal Edition · Midnight Neon UI" << kReset << "\n";
    stream << kMuted << "Bubble Sort playback with snapshot-based rendering and modern terminal cards."
           << kReset << "\n\n";

    std::ostringstream progressLine;
    progressLine << repeat("#", filled) << repeat("-", 24 - filled)
                 << "  " << std::setw(3) << static_cast<int>(progress * 100.0) << "%";

    stream << boxedPanel("Overview",
                         {
                             std::string("Status      ") + playbackStateLabel(playback.state()),
                             std::string("Step        ") + std::to_string(currentStep) + "/" + std::to_string(totalSteps == 0 ? 0 : totalSteps - 1),
                             std::string("Action      ") + stepTypeLabel(step != nullptr ? step->type : StepType::None),
                             std::string("Progress    ") + progressLine.str(),
                         },
                         62)
           << "\n\n";

    stream << boxedPanel("Metrics",
                         {
                             std::string("Comparisons ") + std::to_string(currentMetrics.comparisons),
                             std::string("Swaps       ") + std::to_string(currentMetrics.swaps),
                             std::string("Writes      ") + std::to_string(currentMetrics.writes),
                             std::string("Sorted      ") + std::to_string(currentMetrics.sortedMarks),
                         },
                         62)
           << "\n\n";

    std::vector<std::string> chartLines;
    std::istringstream chart(m_arrayView.buildFrame(step));
    for (std::string line; std::getline(chart, line);) {
        chartLines.push_back(line);
    }
    stream << boxedPanel("Data View",
                         chartLines.empty() ? std::vector<std::string>{"[no data]"} : chartLines,
                         62)
           << "\n\n";

    stream << boxedPanel("Legend",
                         {
                             std::string("@ Compare") + "   active comparison pair",
                             std::string("% Swap") + "      mutation / swap in current frame",
                             std::string("= Sorted") + "    already locked in final position",
                             std::string("# Default") + "   neutral dataset bars",
                         },
                         62)
           << "\n";
}
} // namespace av
