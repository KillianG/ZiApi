//
// Created by killian on 23/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#ifndef PROJECT_AMODULE_HPP
#define PROJECT_AMODULE_HPP

#include <memory>

namespace ZiApi {
    class AModule {
    public:
        AModule(std::string name, float priority = 0) : _name(std::move(name)), _pipelinePriority(priority) {}

        const std::string &getName() const noexcept { return _name; }

        float getPipelinePriority() const noexcept { return  _pipelinePriority; }

    protected:
        std::string _name;

    private:
        float _pipelinePriority;
    };

}

extern "C" {
    std::unique_ptr<ZiApi::AModule> createModule();
}


#endif //PROJECT_AMODULE_HPP
