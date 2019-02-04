//
// Created by nhyarlathotep on 31/01/19.
//

#pragma once

#include "Config.hpp"

class MyConfig : public ZiApi::Config {
public:
    void loadConfig(const std::string &path) override {
        /**
         * It's up to you
         * Open the configuration file to obtain the necessary information
         * Don't forget to create a basic configuration of the file if it doesn't exist or corrupt
         */
    }

    const ZiApi::FieldValue::ValueVariant &operator[](const std::string &key) const override {
        return _configData.at(key)->getValue();
    }
};