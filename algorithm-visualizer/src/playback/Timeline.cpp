#include "playback/Timeline.hpp"

namespace av {
void Timeline::setSteps(std::vector<AlgorithmStep> steps) {
    m_steps = std::move(steps);
}

void Timeline::clear() {
    m_steps.clear();
}

bool Timeline::empty() const {
    return m_steps.empty();
}

std::size_t Timeline::size() const {
    return m_steps.size();
}

const AlgorithmStep* Timeline::tryGet(StepIndex index) const {
    if (index >= m_steps.size()) {
        return nullptr;
    }
    return &m_steps[index];
}

const std::vector<AlgorithmStep>& Timeline::steps() const {
    return m_steps;
}
} // namespace av
