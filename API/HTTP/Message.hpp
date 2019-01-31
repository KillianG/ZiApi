//
// Created by nhyarlathotep on 27/01/19.
//

#pragma once

#include <map>
#include <memory>
#include "FieldValue.hpp"

namespace Http {
    class Message {
    public:
        /**
         * @brief Defines an Http header
         *
         * @note In the rfc2616 section 4.2 an Http header is like :
         * @note message-header = field-name ":" [ field-value ]
         * @sa ZiApi::FieldValue
         */
        using HttpHeader = std::map<std::string, std::shared_ptr<ZiApi::FieldValue>>;

        /**
         * @brief Gets the message's header
         */
        virtual HttpHeader &getHeader() = 0;

        /**
         * @brief Sets the message's body
         */
        virtual void setBody(const std::string &newBody) = 0;

        /**
         * @brief Gets the message's body
         */
        virtual const std::string &getBody() const = 0;

        /**
         * @brief Sets the message's Http version
         */
        virtual void setHttpVersion(uint8_t major, uint8_t minor) = 0;

        /**
         * @brief Gets the message's Http version
         * @return @code "HTTP/major.minor" @endcode
         */
        virtual std::string getHttpVersion() const = 0;

    protected:
        uint8_t _versionMajor;  ///< Message's major version
        uint8_t _versionMinor;  ///< Message's minor version

        HttpHeader _header;     ///< Message's header
        std::string _body;      ///< Message's content
    };
}