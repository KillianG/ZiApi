//
// Created by nhyarlathotep on 31/01/19.
//

#pragma once

#include <iostream>
#include "ModuleManager.hpp"

class MyModuleMgr : public ZiApi::ModuleManager {
public:
    bool load(const std::string &modulePath, ZiApi::Core &core) override {
        /*
         * It's up to you
         * Use the dl functions to load dynamically the modules
         */
        auto mod = createModule(core);                                                  //Calls the extern "C" createModule
        std::cout << "Load Module ["<< mod->getName() << "]" << std::endl;              //Load Module [SSL]
        _modules[mod->getName()] = std::move(mod);
        return false;
    }

    bool unLoad(const std::string &moduleName) override {
        /* It's up to you */
        return false;
    }

    bool isLoaded(const std::string &moduleName) override {
        /* It's up to you */
        return false;
    }

    bool addToPipeline(size_t importance, const std::string &name) override {
        return _pipeline.emplace(std::make_pair(importance, name)).second;                      //Emplace the module in the processing list
    }

    bool removeFromPipeline(const std::string &moduleName) override {
        /* It's up to you */
        return false;
    }

    ZiApi::Module::ModuleStatus runPipeline(Http::Request &request, Http::Response &response) override {
        /* The modules are arranged in order in the pipeline container */
        std::cout << __PRETTY_FUNCTION__ << std::endl;                                          //virtual ZiApi::Module::ModuleStatus MyModuleMgr::runPipeline(Http::Request&, Http::Response&)
        for (auto &it : _pipeline) {
            ZiApi::Module::ModuleStatus ret = _modules[it.second]->handle(request, response);   //Calls the module handle function
            if (ret != ZiApi::Module::ModuleStatus::OK)
                return ret;                                                                     //Breaks if the module returns true
        }
        return ZiApi::Module::ModuleStatus::OK;
    }
};