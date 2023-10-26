//
// Created by Tomasz Stachowiak on 26.10.23.
//

#ifndef FRACTALS3_CONFIGURATIONJSON_H
#define FRACTALS3_CONFIGURATIONJSON_H

#include "Configuration.h"
#include "nlohmann/json.hpp"
#include <format>
#include <fstream>

using json = nlohmann::json;

class ConfigurationJSON : public Configuration {
    std::string pathPrefix;
    json data;


public:
    explicit ConfigurationJSON(json data, std::string prefix)
            : data{data}, pathPrefix(std::move(prefix)) {}

    explicit ConfigurationJSON(const std::string &path) : pathPrefix{} {
        std::ifstream file{path};

        if (!file.is_open()) {
            throw std::runtime_error("Cannot open configuration file ");
        }

        data = json::parse(file);
        file.close();
    }

    [[nodiscard]] const Configuration *getSection(std::string key) const override {
        throwIfMissing(data, key, pathPrefix);

        if (data[key].is_object())
            return new ConfigurationJSON(data[key], pathPrefix + "." + key);


        throw std::runtime_error("ConfigurationJSON::getSection: value under key '" + key + "' is not a section");
    }

    [[nodiscard]] std::string getString(std::string key) const override {
        throwIfMissing(data, key, pathPrefix);

        if (data[key].is_string())
            return data[key].template get<std::string>();

        throw std::runtime_error("ConfigurationJSON::getString: value under key '" + key + "' is not a string");
    }

    [[nodiscard]] complex getComplex(std::string key) const override {
        throwIfMissing(data, key, pathPrefix);

        if (!data[key].is_object())
            throw std::runtime_error("ConfigurationJSON::getComplex: value under key '" + key + "' is not a complex");

        throwIfMissing(data[key], "re", pathPrefix + "." + key);
        throwIfMissing(data[key], "im", pathPrefix + "." + key);

        auto re = data[key]["re"].template get<double>();
        auto im = data[key]["im"].template get<double>();


        return {re, im};
    }

    [[nodiscard]] Size getSize(std::string key) const override {
        if (!data[key].is_object())
            throw std::runtime_error("ConfigurationJSON::getSize: value under key '" + key + "' is not a size");

        throwIfMissing(data[key], "width", pathPrefix + "." + key);
        throwIfMissing(data[key], "height", pathPrefix + "." + key);

        auto width = data[key]["width"].template get<int>();
        auto height = data[key]["height"].template get<int>();


        return {width, height};
    }

    [[nodiscard]] int getInt(std::string key) const override {
        throwIfMissing(data, key, pathPrefix);

        if (data[key].is_number_integer())
            return data[key].template get<int>();

        throw std::runtime_error("ConfigurationJSON::getInt: value under key '" + key + "' is not an integer");
    }

    [[nodiscard]] double getDouble(std::string key) const override {
        throwIfMissing(data, key, pathPrefix);

        if (data[key].is_number_float())
            return data[key].template get<double>();

        throw std::runtime_error("ConfigurationJSON::getDouble: value under key '" + key + "' is not a double");
    }

    [[nodiscard]] bool contains(std::string key) const override {
        return data.contains(key);
    }

private:
    void throwIfMissing(json section, std::string key, std::string path) const {
        if (!section.contains(key))
            throw std::runtime_error(
                    "ConfigurationJSON::throwIfMissing: key '"
                    + key
                    + "' does not exist in section '"
                    + path
                    + "'"
            );
    }

};

#endif //FRACTALS3_CONFIGURATIONJSON_H
