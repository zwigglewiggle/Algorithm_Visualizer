#include "data/DataGenerator.hpp"

#include <cassert>

int main() {
    const av::DataSet random = av::DataGenerator::generate(20, av::DataPresetType::Random);
    assert(random.size() == 20);

    const av::DataSet reversed = av::DataGenerator::generate(5, av::DataPresetType::Reversed);
    assert(reversed.values().front() == 5);
    assert(reversed.values().back() == 1);
    return 0;
}
