//
// Created by nhyarlathotep on 30/01/19.
//

#pragma once

#include <unordered_map>
#include "Config.hpp"
#include "Module.hpp"

namespace ZiApi {
    class Core;

    class ModuleManager {
    public:
        virtual bool load(const std::string &modulePath, Core &core) = 0;

        virtual bool unLoad(const std::string &moduleName) = 0;

        virtual bool isLoaded(const std::string &moduleName) = 0;

        virtual bool addToPipeline(size_t order, const std::string &name) = 0;

        virtual bool runPipeline(HttpRequest &request, HttpResponse &response) = 0;

    protected:
        std::map<size_t, std::string> _pipeline;
        std::unordered_map<std::string, std::unique_ptr<Module>> _modules;
    };
}