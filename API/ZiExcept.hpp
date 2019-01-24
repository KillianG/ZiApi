//
// Created by killian on 22/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#ifndef PROJECT_ZIEXCEPT_HPP
#define PROJECT_ZIEXCEPT_HPP

#include <exception>
#include "ZiLogger.hpp"

namespace ZiApi {
    class ZiExcept : public std::exception {
    public:
        explicit ZiExcept(const std::string &msg) : std::exception(), errorMsg(msg) {
            ZiApi::ZiLogger::Type::ERROR << ZiApi::ZiLogger::Severity::IMPORTANT << msg << ZiApi::ZiLogger::Endl::endl;
        }
        ~ZiExcept() final = default;

        const char* what() const noexcept override { return errorMsg.c_str(); }

    private:
        std::string errorMsg;

    };
}

#endif //PROJECT_ZIEXCEPT_HPP
