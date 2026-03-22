#include "algorithms/common/AlgorithmContext.hpp"
#include "algorithms/sorting/BubbleSort.hpp"

#include <cassert>

int main() {
    av::DataSet data({5, 1, 4, 2, 8}, av::DataPresetType::Fixed);
    av::BubbleSort algorithm;
    const av::AlgorithmResult result = algorithm.run(data, av::AlgorithmContext{});

    assert(result.status.isOk());
    assert(result.finalData.values() == av::DataSet({1, 2, 4, 5, 8}, av::DataPresetType::Fixed).values());
    assert(!result.steps.empty());
    assert(result.steps.back().type == av::StepType::Done);
    return 0;
}
