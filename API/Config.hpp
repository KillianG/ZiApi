//
// Created by nhyarlathotep on 29/01/19.
//

#pragma once

#include <memory>
#include <unordered_map>
#include "FieldValue.hpp"

namespace ZiApi {
    /**
     * @brief Server's config
     *
     * @note The server must be fully configurable by means of a configuration file
     * @note It must be possible to reload the configuration file without restarting nor recompiling the server
     *
     * @include MyConfig.hpp
     */
    class Config {
    public:
        /**
         * @brief Load the config from a file
         * @warning If it the configuration file is corrupt or missing: you must set default values
         */
        virtual void loadConfig(const std::string &path) = 0;

        virtual const FieldValue::ValueVariant &operator[](const std::string &key) const = 0;

    protected:
        /**
         * @brief The Configuration's file data
         * @sa FieldValue::ValueMap
         */
        FieldValue::ValueMap _configData;
    };
}