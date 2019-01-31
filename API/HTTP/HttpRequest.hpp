//
// Created by killian on 22/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#pragma once

#include "HttpMessage.hpp"

namespace ZiApi {
    /**
     * @brief Http request container
     *
     * @sa ZiApi::HttpMessage, ZiApi::HttpResponse
     *
     * MyHttpRequest.hpp : @include MyHttpRequest.hpp
     * MyFieldValue.hpp : @include MyFieldValue.hpp
     * Output : @include MyHttpRequest.output
     * MyHttpRequest.cpp : @example MyHttpRequest.cpp
     */
    class HttpRequest : public HttpMessage {
    public:
        /**
         * Methods list
         */
        enum class MethodType {
            GET,            ///< Retrieves whatever information
            HEAD,           ///< Identical to GET except that the server must not return a message-body in the response
            POST,           ///< Sends data to the server
            PUT,            ///< Replaces all current representations of the target resource with the uploaded content
            DELETE,         ///< Removes all current representations of the target resource given by a uri
            CONNECT,        ///< Establishes a tunnel to the server identified by a given uri
            OPTIONS,        ///< Describes the communication options for the target resource
            TRACE           ///< Performs a message loop-back test along the path to the target resource
        };

        /**
         * @brief Sets the request's uri
         */
        virtual void setUri(const std::string &newUri) = 0;

        /**
         * @brief Gets the request's uri
         */
        virtual const std::string &getUri() const = 0;

        /**
         * @brief Sets the request's method
         */
        virtual void setMethod(MethodType newMethod) = 0;

        /**
         * @brief Gets the request's method
         */
        virtual MethodType getMethod() const = 0;

    protected:
        std::string _uri;   ///< Request's uri
        MethodType _method; ///< Request's method
    };
}