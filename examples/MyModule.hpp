//
// Created by nhyarlathotep on 31/01/19.
//

#pragma once

#include <iostream>
#include "Core.hpp"
#include "Module.hpp"
#include "MyFieldValue.hpp"

class SSLModule : public ZiApi::Module {
public:
    SSLModule(ZiApi::Core &core) {
        _name = "SSL";
        int priority = 0;                                                               //The module priority can be set in the config file
        core.getModuleMgr()->addToPipeline(priority, _name);                            //Add the module to the processing list
    };

    const std::string &getName() const noexcept override { return _name; }

    ModuleStatus handle(Http::Request &request, Http::Response &response) override {
        /* It's up to you */
        std::cout << __PRETTY_FUNCTION__ << std::endl;                                  //virtual ZiApi::Module::ModuleStatus SSLModule::handle(Http::Request&, Http::Response&)

        auto &header = response.getHeader();

        header["Host"] = std::make_shared<MyValue>("127.0.0.1:4242");                   //Sets the response's header

        response.setHttpVersion(1, 1);                                                  //Sets the response's http version
        response.setStatusMessage("OK");                                                //Sets the response's status message
        response.setStatusCode(Http::Response::StatusCode::OK);                         //Sets the response's status code
        response.setBody("<html><body><h1>Title</h1></body></html>");                   //Sets the response's body

        return ModuleStatus::OK;
    }
};

extern "C" {
std::unique_ptr<ZiApi::Module> createModule(ZiApi::Core &core) {                        //It will be called by the dl functions
    return std::make_unique<SSLModule>(core);                                           //Gives the Core to the module if needed
}
}