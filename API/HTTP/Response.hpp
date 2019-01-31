//
// Created by killian on 22/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#pragma once

#include <string>
#include "Message.hpp"

namespace Http {
    /**
     * @brief Http response container
     *
     * @sa Message, Request
     */
    class Response : public Message {
    public:
        /**
         * Status list
         * @note @b 1xx Informational : It means the request has been received and the process is continuing
         * @note @b 2xx Success : It means the action was successfully received, understood, and accepted
         * @note @b 3xx Redirection : It means further action must be taken in order to complete the request
         * @note @b 4xx Client Error : It means the request contains incorrect syntax or cannot be fulfilled
         * @note @b 5xx Server Error : It means the server failed to fulfill an apparently valid request
         */
        enum class StatusCode {
            UndefinedStatusCode = 0,                ///<@b 0 May throw if it used
            Continue = 100,                         ///<@b 100 Only a part of the request has been received by the server, but as long as it has not been rejected, the client should continue with the request
            SwitchingProtocols = 101,               ///<@b 101 The server switches protocol
            OK = 200,                               ///<@b 200 The request is OK
            Created = 201,                          ///<@b 201 The request is complete, and a new resource is created
            Accepted = 202,                         ///<@b 202 The request is accepted for processing, but the processing is not complete
            NonAuthoritativeInformation = 203,      ///<@b 203 The information in the entity header is from a local or third-party copy, not from the original server
            NoContent = 204,                        ///<@b 204 A status code and a header are given in the response, but there is no entity-body in the reply
            ResetContent = 205,                     ///<@b 205 The browser should clear the form used for this transaction for additional input
            PartialContent = 206,                   ///<@b 206 The server is returning partial data of the size requested. Used in response to a request specifying a Range header. The server must specify the range included in the response with the Content-Range header
            MultipleChoices = 300,                  ///<@b 300 A link list. The user can select a link and go to that location. Maximum five addresses
            MovedPermanently = 301,                 ///<@b 301 The requested page has moved to a new url
            Found = 302,                            ///<@b 302 The requested page has moved temporarily to a new url
            SeeOther = 303,                         ///<@b 303 The requested page can be found under a different url
            NotModified = 304,                      ///<@b 304 This is the response code to an If-Modified-Since or If-None-Match header, where the URL has not been modified since the specified date
            UseProxy = 305,                         ///<@b 305 The requested URL must be accessed through the proxy mentioned in the Location header
            Unused = 306,                           ///<@b 306 This code was used in a previous version. It is no longer used, but the code is reserved
            TemporaryRedirect = 307,                ///<@b 307 The requested page has moved temporarily to a new url
            BadRequest = 400,                       ///<@b 400 The server did not understand the request
            Unauthorized = 401,                     ///<@b 401 The requested page needs a username and a password
            PaymentRequired = 402,                  ///<@b 402 You can not use this code yet
            Forbidden = 403,                        ///<@b 403 Access is forbidden to the requested page
            NotFound = 404,                         ///<@b 404 The server can not find the requested page
            MethodNotAllowed = 405,                 ///<@b 405 The method specified in the request is not allowed
            NotAcceptable = 406,                    ///<@b 406 The server can only generate a response that is not accepted by the client
            ProxyAuthenticationRequired = 407,      ///<@b 407 You must authenticate with a proxy server before this request can be served
            RequestTimeOut = 408,                   ///<@b 408 The request took longer than the server was prepared to wait
            Conflict = 409,                         ///<@b 409 The request could not be completed because of a conflict
            Gone = 410,                             ///<@b 410 The requested page is no longer available
            LengthRequired = 411,                   ///<@b 411 The "Content-Length" is not defined. The server will not accept the request without it
            PreconditionFailed = 412,               ///<@b 412 The pre condition given in the request evaluated to false by the server
            RequestEntityTooLarge = 413,            ///<@b 413 The server will not accept the request, because the request entity is too large
            RequestURITooLarge = 414,               ///<@b 414 The server will not accept the request, because the url is too long. Occurs when you convert a "post" request to a "get" request with a long query information
            UnsupportedMediaType = 415,             ///<@b 415 The server will not accept the request, because the mediatype is not supported
            RequestedRangeNotSatisfiable = 416,     ///<@b 416 The requested byte range is not available and is out of bounds
            ExpectationFailed = 417,                ///<@b 417 The expectation given in an Expect request-header field could not be met by this server
            InternalServerError = 500,              ///<@b 500 The request was not completed. The server met an unexpected condition
            NotImplemented = 501,                   ///<@b 501 The request was not completed. The server did not support the functionality required
            BadGateway = 502,                       ///<@b 502 The request was not completed. The server received an invalid response from the upstream server
            ServiceUnavailable = 503,               ///<@b 503 The request was not completed. The server is temporarily overloading or down
            GatewayTimeOut = 504,                   ///<@b 504 The gateway has timed out
            HTTPVersionNotSupported = 505           ///<@b 505 The server does not support the "http protocol" version
        };

        /**
         * @brief Sets the response's status code
         */
        virtual void setStatusCode(StatusCode newCode) = 0;

        /**
         * @brief Gets the response's status code
         */
        virtual StatusCode getStatusCode() const = 0;

        /**
         * @brief Sets the response's status message
         */
        virtual void setStatusMessage(const std::string &newMessage) = 0;

        /**
         * @brief Gets the response's status message
         */
        virtual const std::string &getStatusMessage() const = 0;

    protected:
        StatusCode _statusCode;                     ///< Response's status-code
        std::string _statusMessage;                 ///< Response's status-message
    };
}