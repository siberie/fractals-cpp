//
// Created by Tomasz Stachowiak on 26.10.23.
//

#ifndef FRACTALS3_CONFIGURATIONFACTORY_H
#define FRACTALS3_CONFIGURATIONFACTORY_H

#include "Configuration.h"
#include "ConfigurationJSON.h"

class ConfigurationFactory {
public:
    static Configuration* fromJSONFile(const char *fileName) {
        return new ConfigurationJSON(fileName);
    }
};

#endif //FRACTALS3_CONFIGURATIONFACTORY_H
