#pragma once

#include "algorithms/common/AlgorithmStep.hpp"

#include <vector>

namespace av {
class Timeline {
public:
    void setSteps(std::vector<AlgorithmStep> steps);
    void clear();
    bool empty() const;
    std::size_t size() const;
    const AlgorithmStep* tryGet(StepIndex index) const;
    const std::vector<AlgorithmStep>& steps() const;

private:
    std::vector<AlgorithmStep> m_steps{};
};
} // namespace av
