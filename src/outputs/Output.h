//
// Created by Tomasz Stachowiak on 26.10.23.
//

#ifndef FRACTALS3_OUTPUT_H
#define FRACTALS3_OUTPUT_H

#include "../defaults.h"
#include "../collections/Grid.h"


/// Abstract class for image output.
class Output {
public:
    /// Writes fractal to output.
    virtual void write(Grid<Color> fractal) = 0;
};

#endif //FRACTALS3_OUTPUT_H
