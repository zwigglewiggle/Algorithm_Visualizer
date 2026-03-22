#pragma once

#include "algorithms/common/AlgorithmContext.hpp"
#include "algorithms/common/AlgorithmStep.hpp"
#include "algorithms/common/DataSet.hpp"
#include "core/Result.hpp"

#include <string>
#include <vector>

namespace av {
struct AlgorithmResult {
    DataSet finalData{};
    std::vector<AlgorithmStep> steps{};
    Metrics metrics{};
    Result status{Result::success()};
};

class Algorithm {
public:
    virtual ~Algorithm() = default;

    virtual std::string getName() const = 0;
    virtual AlgorithmCategory getCategory() const = 0;
    virtual Result validate(const DataSet& dataSet) const = 0;
    virtual AlgorithmResult run(const DataSet& dataSet, const AlgorithmContext& context) const = 0;
};
} // namespace av
