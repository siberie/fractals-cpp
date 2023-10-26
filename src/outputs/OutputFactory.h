//
// Created by Tomasz Stachowiak on 26.10.23.
//

#ifndef FRACTALS3_OUTPUT_FACTORY_H
#define FRACTALS3_OUTPUT_FACTORY_H

#include "Output.h"
#include "OutputBitmap.h"
#include "../configuration/Configuration.h"

class OutputFactory {
public:
    static Output *withConfiguration(const Configuration *configuration) {
        auto section = configuration->getSection("output");
        auto fileName = section->getString("path");
        auto resolution = section->getSize("resolution");

        return new OutputBitmap(fileName, resolution.width, resolution.height);
    }
};

#endif //FRACTALS3_OUTPUT_FACTORY_H
