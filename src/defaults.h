//
// Created by Tomasz Stachowiak on 25.10.23.
//

#ifndef FRACTALS3_DEFAULTS_H
#define FRACTALS3_DEFAULTS_H

#include <complex>
#include <tuple>

typedef std::complex<double> complex;
typedef std::tuple<uint8_t, uint8_t, uint8_t> Color;

struct Size {
    int width;
    int height;
};

#endif //FRACTALS3_DEFAULTS_H
