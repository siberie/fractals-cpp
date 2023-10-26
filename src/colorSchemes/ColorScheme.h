//
// Created by Tomasz Stachowiak on 26.10.23.
//

#ifndef FRACTALS3_COLORSCHEME_H
#define FRACTALS3_COLORSCHEME_H

#include "../defaults.h"


/// Abstract class for color schemes.
class ColorScheme {
public:
    /// Returns rgb color for given index.
    virtual Color getColor(uint16_t index) = 0;
};

#endif //FRACTALS3_COLORSCHEME_H
