//
// Created by killian on 22/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#pragma once

#include <exception>
#include "ZiLogger.hpp"

namespace ZiApi {
    /**
     * @brief ZiApi Exception
     */
    class ZiExcept : public std::exception {
    public:
        explicit ZiExcept(const std::string &msg) : std::exception(), errorMsg(msg) {
            ZiLogger::Type::ERROR << ZiLogger::Severity::IMPORTANT << msg << ZiLogger::endl;
        }

        ~ZiExcept() final = default;

        const char *what() const noexcept override { return errorMsg.c_str(); }

    private:
        std::string errorMsg;
    };
}