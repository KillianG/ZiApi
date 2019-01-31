//
// Created by nhyarlathotep on 31/01/19.
//

#pragma once

#include "Config.hpp"

class MyConfig : public ZiApi::Config {
public:
    void loadConfig(const std::string &path) override { /*It is up to you*/ }

    const ZiApi::FieldValue::ValueVariant &operator[](const std::string &key) const override {
        return _configData.at(key)->getValue();
    }
};