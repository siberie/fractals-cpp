//
// Created by Tomasz Stachowiak on 25.10.23.
//

#ifndef FRACTALS3_CONFIGURATION_H
#define FRACTALS3_CONFIGURATION_H

#include "../defaults.h"

class Configuration {
public:
    [[nodiscard]] virtual const Configuration *getSection(std::string key) const = 0;

    [[nodiscard]] virtual std::string getString(std::string key) const = 0;

    [[nodiscard]] virtual complex getComplex(std::string key) const = 0;

    [[nodiscard]] virtual Size getSize(std::string key) const = 0;

    [[nodiscard]] virtual int getInt(std::string key) const = 0;

    [[nodiscard]] virtual double getDouble(std::string key) const = 0;

    [[nodiscard]] virtual bool contains(std::string key) const = 0;
};

#endif //FRACTALS3_CONFIGURATION_H
