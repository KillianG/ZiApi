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
        explicit ZiExcept(std::string msg);

        virtual ~ZiExcept() = default;

        const std::string getErrorMsg() const;

        const char* what() const noexcept;

    private:
        std::string errorMsg;

    };
}

#endif //PROJECT_ZIEXCEPT_HPP
