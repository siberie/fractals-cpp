//
// Created by Tomasz Stachowiak on 26.10.23.
//

#ifndef FRACTALS3_GRID_FACTORY_H
#define FRACTALS3_GRID_FACTORY_H

#include "ComplexGrid.h"
#include "../configuration/Configuration.h"

class GridFactory {
public:
    static ComplexGrid withConfiguration(const Configuration *configuration) {
        auto section = configuration->getSection("grid");
        auto center = section->getComplex("center");
        auto scale = section->getDouble("scale");
        auto resolution = configuration->getSection("output")->getSize("resolution");

        return ComplexGrid::centeredAt(
                center,
                scale,
                resolution.width,
                resolution.height
        );
    }
};

#endif //FRACTALS3_GRID_FACTORY_H
