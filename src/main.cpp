#include "algorithms/AlgorithmFactory.h"
#include "colorSchemes/ColorSchemeFactory.h"
#include "outputs/OutputFactory.h"
#include "collections/GridFactory.h"
#include "configuration/ConfigurationJSON.h"
#include "configuration/ConfigurationFactory.h"

int main() {
    auto configuration = ConfigurationFactory::fromJSONFile("config.json");
    auto grid = GridFactory::withConfiguration(configuration);
    auto scheme = ColorSchemeFactory::withConfiguration(configuration);
    auto output = OutputFactory::withConfiguration(configuration);
    auto algorithm = AlgorithmFactory::withConfiguration(configuration);

    output->write(
            grid
                    .map([=](auto value) { return (*algorithm)(value); })
                    .map([=](auto value) {
                        return scheme->getColor(value);
                    })
    );

    return 0;
}
