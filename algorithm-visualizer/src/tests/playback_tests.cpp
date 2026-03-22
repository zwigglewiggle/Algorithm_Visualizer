#include "algorithms/common/AlgorithmContext.hpp"
#include "algorithms/sorting/BubbleSort.hpp"
#include "playback/PlaybackController.hpp"

#include <cassert>

int main() {
    av::BubbleSort algorithm;
    av::AlgorithmResult result = algorithm.run(av::DataSet({3, 2, 1}, av::DataPresetType::Fixed), av::AlgorithmContext{});

    av::PlaybackController playback;
    playback.load(result);
    assert(playback.currentIndex() == 0);
    playback.stepForward();
    assert(playback.currentIndex() == 1);
    playback.reset();
    assert(playback.currentIndex() == 0);
    return 0;
}
