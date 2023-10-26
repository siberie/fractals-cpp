//
// Created by Tomasz Stachowiak on 25.04.22.
//

#ifndef FRACTALS_JULIA_H
#define FRACTALS_JULIA_H

#include <iostream>

#include "../defaults.h"
#include "Algorithm.h"

template<typename Func>
class Julia : public Algorithm {
    const double limit = 2.0;
    const int maxIndex;
    const Func func;
public:
    explicit Julia(
            const int maxIndex,
            Func func
    ) : maxIndex(maxIndex), func{func} {}

    uint16_t operator()(complex z) const final {
        int index = 0;

        while (norm(z) < limit && index++ < maxIndex) {
            z = func(z);
        }

        return index;
    }
};

#endif //FRACTALS_JULIA_H
