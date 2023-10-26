//
// Created by Tomasz Stachowiak on 26.10.23.
//

#ifndef FRACTALS3_GRAYSCALE_SCHEME_H
#define FRACTALS3_GRAYSCALE_SCHEME_H

#include "ColorScheme.h"
#include "../defaults.h"


/// Grayscale color scheme.
class GrayscaleScheme : public ColorScheme {
public:
    const int maxValue;

    explicit GrayscaleScheme(int maxValue) : maxValue(maxValue) {}

    Color getColor(uint16_t index) final {
        const auto value = (uint8_t) ((((uint32_t) index << 8) / maxValue) & 0xFF);

        return {value, value, value};
    }
};

#endif //FRACTALS3_GRAYSCALE_SCHEME_H
