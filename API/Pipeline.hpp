//
// Created by nhyarlathotep on 24/01/19.
//

#ifndef PROJECT_PIPELINE_HPP
#define PROJECT_PIPELINE_HPP

#include <map>
#include <memory>

#include "ZiExcept.hpp"
#include "AModule.hpp"

namespace ZiApi {
    class Pipeline {
    public:
        void registerModule(std::unique_ptr<AModule> &&module) {
            if (module->getPipelinePriority() < 0.0f || module->getPipelinePriority() > 1.0f)
                throw ZiExcept("Module \"" + module->getName() + "\" priority must be in [0.0 - 1.0]");
            _modulesList.emplace(std::make_pair(module->getPipelinePriority(), std::move(module)));
        }

//        void run(HttpRequest &request) {
//            for (auto &it : _modulesList)
//                std::cout << it.first << std::endl;
//        }

    private:
        std::multimap<float, std::unique_ptr<AModule>> _modulesList;
    };
}

#endif //PROJECT_PIPELINE_HPP