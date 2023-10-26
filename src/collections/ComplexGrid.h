//
// Created by Tomasz Stachowiak on 25.10.23.
//

#ifndef FRACTALS3_COMPLEX_GRID_H
#define FRACTALS3_COMPLEX_GRID_H


#include <algorithm>
#include "../defaults.h"
#include "Grid.h"

class ComplexGrid : public Grid<complex> {
public:
    static ComplexGrid
    centeredAt(element center, double scale, int horizontalResolution, int verticalResolution) {
        ComplexGrid grid{horizontalResolution, verticalResolution};

        for (int x = 0; x < horizontalResolution; x++) {
            for (int y = 0; y < verticalResolution; y++) {
                grid[x, y] = {
                        center.real() - (horizontalResolution * scale) / 2 + scale * x,
                        center.imag() - (verticalResolution * scale) / 2 + scale * y
                };
            }
        }

        return grid;
    }

protected:
    ComplexGrid(int width, int height) : Grid{width, height} {}
};

#endif //FRACTALS3_COMPLEX_GRID_H
