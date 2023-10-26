//
// Created by Tomasz Stachowiak on 26.10.23.
//

#ifndef FRACTALS3_ALGORITHM_H
#define FRACTALS3_ALGORITHM_H

#include "../defaults.h"

class Algorithm {
public:
    virtual uint16_t operator()(complex z) const = 0;
};

#endif //FRACTALS3_ALGORITHM_H
