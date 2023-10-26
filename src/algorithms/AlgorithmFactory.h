//
// Created by Tomasz Stachowiak on 25.10.23.
//

#ifndef FRACTALS3_ALGORITHM_FACTORY_H
#define FRACTALS3_ALGORITHM_FACTORY_H

#include "Algorithm.h"
#include "../configuration/Configuration.h"
#include "Mandelbrot.h"
#include "Julia.h"

class AlgorithmFactory {
public:
    static Algorithm *withConfiguration(const Configuration *configuration) {
        auto section = configuration->getSection("algorithm");

        auto name = section->getString("name");
        auto maxIterations = section->getInt("maxIterations");

        if (name == "mandelbrot") {
            return new Mandelbrot{
                    maxIterations,
                    [](complex z, complex c) {
                        return z * z + c;
                    }
            };
        } else if (name == "julia") {
            if (!section->contains("c"))
                throw std::invalid_argument(
                        "Julia algorithm requires the 'algorithm.c' complex parameter to be defined"
                );

            const auto c = section->getComplex("c");

            return new Julia{
                    maxIterations, [=](complex z) {
                        return z * z + c;
                    }
            };
        } else {
            throw std::invalid_argument("Unknown algorithm type");
        }
    }
};

#endif //FRACTALS3_ALGORITHM_FACTORY_H
