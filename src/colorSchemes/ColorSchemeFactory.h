//
// Created by Tomasz Stachowiak on 26.10.23.
//

#ifndef FRACTALS3_COLOR_SCHEME_FACTORY_H
#define FRACTALS3_COLOR_SCHEME_FACTORY_H

#include "GrayscaleScheme.h"
#include "../configuration/Configuration.h"

class ColorSchemeFactory {
public:
    static ColorScheme *withConfiguration(const Configuration *configuration) {
        auto section = configuration->getSection("output");
        auto name = section->getString("scheme");

        if (name == "grayscale") {
            return new GrayscaleScheme(configuration->getSection("algorithm")->getInt("maxIterations"));
        }

        throw std::runtime_error("Unknown color scheme");
    }
};

#endif //FRACTALS3_COLOR_SCHEME_FACTORY_H
