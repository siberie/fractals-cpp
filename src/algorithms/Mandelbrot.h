//
// Created by Tomasz Stachowiak on 25.04.22.
//

#ifndef FRACTALS2_MANDELBROT_H
#define FRACTALS2_MANDELBROT_H

#include "../defaults.h"
#include "Algorithm.h"

template<typename Func>
struct Mandelbrot : public Algorithm {
    const double limit = 2.0;
    const int maxIndex;
    const Func func;

    Mandelbrot(const int maxIndex, const Func func) : maxIndex(maxIndex),
                                                      func(func) {}

public:
    uint16_t operator()(complex z) const final {
        int index = 0;

        auto res = z;

        while (index++ < maxIndex && norm(res) < limit) {
            res = func(res, z);
        }

        return index;
    }
};

#endif //FRACTALS2_MANDELBROT_H
