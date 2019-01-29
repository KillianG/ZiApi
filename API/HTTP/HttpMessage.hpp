//
// Created by nhyarlathotep on 27/01/19.
//

#pragma once

#include "HttpHeader.hpp"

namespace ZiApi {
    class HttpMessage {
    public:
        /**
         * @brief Gets the message's header
         */
        virtual HttpHeader &getHeader() noexcept = 0;

        /**
         * @brief Sets the message's body
         */
        virtual void setBody(const std::string &newBody) noexcept = 0;

        /**
         * @brief Gets the message's body
         */
        virtual const std::string &getBody() const noexcept = 0;

        /**
         * @brief Sets the message's Http version
         */
        virtual void setHttpVersion(uint8_t major, uint8_t minor) noexcept = 0;

        /**
         * @brief Gets the message's Http version
         * @return @code "HTTP/major.minor" @endcode
         */
        virtual std::string getHttpVersion() const noexcept = 0;

    protected:
        uint8_t _versionMajor;  ///< Message's major version
        uint8_t _versionMinor;  ///< Message's minor version

        HttpHeader _header;     ///< Message's header
        std::string _body;      ///< Message's content
    };
}
