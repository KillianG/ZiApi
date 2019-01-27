//
// Created by killian on 22/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#pragma once

#include <string>
#include "HttpHeader.hpp"

namespace ZiApi {
    struct HttpResponse {
        enum class StatusCode {
            UndefinedStatusCode = 0, Continue = 100, SwitchingProtocols = 101, OK = 200, Created = 201, Accepted = 202,
            NonAuthoritativeInformation = 203, NoContent = 204, ResetContent = 205, PartialContent = 206,
            MultipleChoices = 300, MovedPermanently = 301, Found = 302, SeeOther = 303, NotModified = 304,
            UseProxy = 305, TemporaryRedirect = 307, BadRequest = 400, Unauthorized = 401, PaymentRequired = 402,
            Forbidden = 403, NotFound = 404, MethodNotAllowed = 405, NotAcceptable = 406,
            ProxyAuthenticationRequired = 407, RequestTimeOut = 408, Conflict = 409, Gone = 410, LengthRequired = 411,
            PreconditionFailed = 412, RequestEntityTooLarge = 413, RequestURITooLarge = 414, UnsupportedMediaType = 415,
            RequestedRangeNotSatisfiable = 416, ExpectationFailed = 417, InternalServerError = 500,
            NotImplemented = 501, BadGateway = 502, ServiceUnavailable = 503, GatewayTimeOut = 504,
            HTTPVersionNotSupported = 505
        };

        friend std::ostream &operator<<(std::ostream &os, HttpResponse::StatusCode code) {
            switch (code) {
                case StatusCode::UndefinedStatusCode: return os << static_cast<int>(code) << " UndefinedStatusCode";
                case StatusCode::Continue: return os << static_cast<int>(code) << " Continue";
                case StatusCode::SwitchingProtocols: return os << static_cast<int>(code) << " SwitchingProtocols";
                case StatusCode::OK: return os << static_cast<int>(code) << " OK";
                case StatusCode::Created: return os << static_cast<int>(code) << " Created";
                case StatusCode::Accepted: return os << static_cast<int>(code) << " Accepted";
                case StatusCode::NonAuthoritativeInformation: return os << static_cast<int>(code) << " NonAuthoritativeInformation";
                case StatusCode::NoContent: return os << static_cast<int>(code) << " NoContent";
                case StatusCode::ResetContent: return os << static_cast<int>(code) << " ResetContent";
                case StatusCode::PartialContent: return os << static_cast<int>(code) << " PartialContent";
                case StatusCode::MultipleChoices: return os << static_cast<int>(code) << " MultipleChoices";
                case StatusCode::MovedPermanently: return os << static_cast<int>(code) << " MovedPermanently";
                case StatusCode::Found: return os << static_cast<int>(code) << " Found";
                case StatusCode::SeeOther: return os << static_cast<int>(code) << " SeeOther";
                case StatusCode::NotModified: return os << static_cast<int>(code) << " NotModified";
                case StatusCode::UseProxy: return os << static_cast<int>(code) << " UseProxy";
                case StatusCode::TemporaryRedirect: return os << static_cast<int>(code) << " TemporaryRedirect";
                case StatusCode::BadRequest: return os << static_cast<int>(code) << " BadRequest";
                case StatusCode::Unauthorized: return os << static_cast<int>(code) << " Unauthorized";
                case StatusCode::PaymentRequired: return os << static_cast<int>(code) << " PaymentRequired";
                case StatusCode::Forbidden: return os << static_cast<int>(code) << " Forbidden";
                case StatusCode::NotFound: return os << static_cast<int>(code) << " Not found";
                case StatusCode::MethodNotAllowed: return os << static_cast<int>(code) << " MethodNotAllowed";
                case StatusCode::NotAcceptable: return os << static_cast<int>(code) << " NotAcceptable";
                case StatusCode::ProxyAuthenticationRequired: return os << static_cast<int>(code) << " ProxyAuthenticationRequired";
                case StatusCode::RequestTimeOut: return os << static_cast<int>(code) << " RequestTimeOut";
                case StatusCode::Conflict: return os << static_cast<int>(code) << " Conflict";
                case StatusCode::Gone: return os << static_cast<int>(code) << " Gone";
                case StatusCode::LengthRequired: return os << static_cast<int>(code) << " LengthRequired";
                case StatusCode::PreconditionFailed: return os << static_cast<int>(code) << " PreconditionFailed";
                case StatusCode::RequestEntityTooLarge: return os << static_cast<int>(code) << " RequestEntityTooLarge";
                case StatusCode::RequestURITooLarge: return os << static_cast<int>(code) << " RequestURITooLarge";
                case StatusCode::UnsupportedMediaType: return os << static_cast<int>(code) << " UnsupportedMediaType";
                case StatusCode::RequestedRangeNotSatisfiable: return os << static_cast<int>(code) << " RequestedRangeNotSatisfiable";
                case StatusCode::ExpectationFailed: return os << static_cast<int>(code) << " ExpectationFailed";
                case StatusCode::InternalServerError: return os << static_cast<int>(code) << " InternalServerError";
                case StatusCode::NotImplemented: return os << static_cast<int>(code) << " NotImplemented";
                case StatusCode::BadGateway: return os << static_cast<int>(code) << " BadGateway";
                case StatusCode::ServiceUnavailable: return os << static_cast<int>(code) << " ServiceUnavailable";
                case StatusCode::GatewayTimeOut: return os << static_cast<int>(code) << " GatewayTimeOut";
                case StatusCode::HTTPVersionNotSupported: return os << static_cast<int>(code) << " HTTPVersionNotSupported";
            }
            return os << "Unknown";
        }
    };
}