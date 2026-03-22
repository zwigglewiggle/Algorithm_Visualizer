#pragma once

#include <SFML/Graphics/Color.hpp>

namespace av {
struct ColorPalette {
    sf::Color background{18, 18, 24};
    sf::Color panel{28, 32, 44};
    sf::Color bar{95, 168, 250};
    sf::Color compare{255, 200, 87};
    sf::Color swap{255, 107, 107};
    sf::Color sorted{80, 227, 194};
    sf::Color accent{173, 216, 230};
};
} // namespace av
