#pragma once

#include "algorithms/common/Algorithm.hpp"

namespace av {
class BubbleSort final : public Algorithm {
public:
    std::string getName() const override { return "Bubble Sort"; }
    AlgorithmCategory getCategory() const override { return AlgorithmCategory::Sorting; }
    Result validate(const DataSet& dataSet) const override { return dataSet.validate(); }
    AlgorithmResult run(const DataSet& dataSet, const AlgorithmContext& context) const override;
};
} // namespace av
