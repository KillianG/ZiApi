//
// Created by nhyarlathotep on 30/01/19.
//

#pragma once

#include <unordered_map>
#include "Config.hpp"
#include "Module.hpp"

namespace ZiApi {
    class Core;

    /**
     * @brief Server's module manager
     *
     * Usage example :
     * @include MyModuleManager.hpp
     */
    class ModuleManager {
    public:
        virtual bool load(const std::string &modulePath, Core &core) = 0;

        virtual bool unLoad(const std::string &moduleName) = 0;

        /**
         * @brief Checks if the module is loaded
         */
        virtual bool isLoaded(const std::string &moduleName) = 0;

        /**
         * @brief Adds the module to the processing list
         * @param[in] importance The order(from the smallest to the biggest) of the modules in the processing list
         */
        virtual bool addToPipeline(size_t importance, const std::string &moduleName) = 0;

        /**
         * @brief Removes the module from the processing list
         */
        virtual bool removeFromPipeline(const std::string &moduleName) = 0;

        /**
         * @brief Calls all modules's handle function
         * @note Breaks the loop if Module::handle returns true
         */
        virtual bool runPipeline(Http::Request &request, Http::Response &response) = 0;

    protected:
        std::map<size_t, std::string> _pipeline;                            ///<Module's processing list ordered by a size_t
        std::unordered_map<std::string, std::unique_ptr<Module>> _modules;  ///<Loaded module list
    };
}