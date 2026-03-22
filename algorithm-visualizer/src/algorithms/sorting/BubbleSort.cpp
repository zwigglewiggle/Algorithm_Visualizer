#include "algorithms/sorting/BubbleSort.hpp"

namespace av {
namespace {
AlgorithmStep makeStep(StepType type,
                       const DataSet& data,
                       const std::vector<bool>& sortedMask,
                       const Metrics& metrics,
                       Index first = kInvalidIndex,
                       Index second = kInvalidIndex) {
    AlgorithmStep step;
    step.type = type;
    step.indices = {first, second};
    step.snapshot = data.values();
    step.sortedMask = sortedMask;
    step.metrics = metrics;
    if (first != kInvalidIndex && first < data.size()) {
        step.values[0] = data.values()[first];
    }
    if (second != kInvalidIndex && second < data.size()) {
        step.values[1] = data.values()[second];
    }
    return step;
}
} // namespace

AlgorithmResult BubbleSort::run(const DataSet& source, const AlgorithmContext&) const {
    AlgorithmResult result;
    auto validation = validate(source);
    if (validation.isError()) {
        result.status = validation;
        return result;
    }

    DataSet data = source;
    std::vector<bool> sortedMask(data.size(), false);
    Metrics metrics;

    for (std::size_t i = 0; i < data.size(); ++i) {
        for (std::size_t j = 0; j + 1 < data.size() - i; ++j) {
            ++metrics.comparisons;
            result.steps.push_back(makeStep(StepType::Compare, data, sortedMask, metrics, j, j + 1));

            DataValue left{};
            DataValue right{};
            data.tryGet(j, left);
            data.tryGet(j + 1, right);
            if (left > right) {
                data.swap(j, j + 1);
                ++metrics.swaps;
                result.steps.push_back(makeStep(StepType::Swap, data, sortedMask, metrics, j, j + 1));
            }
        }

        sortedMask[data.size() - i - 1] = true;
        ++metrics.sortedMarks;
        result.steps.push_back(makeStep(StepType::MarkSorted, data, sortedMask, metrics, data.size() - i - 1));
    }

    result.metrics = metrics;
    result.finalData = data;
    result.steps.push_back(makeStep(StepType::Done, data, sortedMask, metrics));
    result.status = Result::success();
    return result;
}
} // namespace av
