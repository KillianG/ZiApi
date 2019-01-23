//
// Created by killian on 22/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#ifndef PROJECT_IHTTPRESPONSE_HPP
#define PROJECT_IHTTPRESPONSE_HPP

#include <string>

namespace ZiApi {
    class IHttpResponse {
    public:
        enum StatusCode {
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

        friend std::ostream &operator<<(std::ostream &os, IHttpResponse::StatusCode code) {
            switch (code) {
                case UndefinedStatusCode: return os << static_cast<int>(code) << " UndefinedStatusCode";
                case Continue: return os << static_cast<int>(code) << " Continue";
                case SwitchingProtocols: return os << static_cast<int>(code) << " SwitchingProtocols";
                case OK: return os << static_cast<int>(code) << " OK";
                case Created: return os << static_cast<int>(code) << " Created";
                case Accepted: return os << static_cast<int>(code) << " Accepted";
                case NonAuthoritativeInformation: return os << static_cast<int>(code) << " NonAuthoritativeInformation";
                case NoContent: return os << static_cast<int>(code) << " NoContent";
                case ResetContent: return os << static_cast<int>(code) << " ResetContent";
                case PartialContent: return os << static_cast<int>(code) << " PartialContent";
                case MultipleChoices: return os << static_cast<int>(code) << " MultipleChoices";
                case MovedPermanently: return os << static_cast<int>(code) << " MovedPermanently";
                case Found: return os << static_cast<int>(code) << " Found";
                case SeeOther: return os << static_cast<int>(code) << " SeeOther";
                case NotModified: return os << static_cast<int>(code) << " NotModified";
                case UseProxy: return os << static_cast<int>(code) << " UseProxy";
                case TemporaryRedirect: return os << static_cast<int>(code) << " TemporaryRedirect";
                case BadRequest: return os << static_cast<int>(code) << " BadRequest";
                case Unauthorized: return os << static_cast<int>(code) << " Unauthorized";
                case PaymentRequired: return os << static_cast<int>(code) << " PaymentRequired";
                case Forbidden: return os << static_cast<int>(code) << " Forbidden";
                case NotFound: return os << static_cast<int>(code) << " Not found";
                case MethodNotAllowed: return os << static_cast<int>(code) << " MethodNotAllowed";
                case NotAcceptable: return os << static_cast<int>(code) << " NotAcceptable";
                case ProxyAuthenticationRequired: return os << static_cast<int>(code) << " ProxyAuthenticationRequired";
                case RequestTimeOut: return os << static_cast<int>(code) << " RequestTimeOut";
                case Conflict: return os << static_cast<int>(code) << " Conflict";
                case Gone: return os << static_cast<int>(code) << " Gone";
                case LengthRequired: return os << static_cast<int>(code) << " LengthRequired";
                case PreconditionFailed: return os << static_cast<int>(code) << " PreconditionFailed";
                case RequestEntityTooLarge: return os << static_cast<int>(code) << " RequestEntityTooLarge";
                case RequestURITooLarge: return os << static_cast<int>(code) << " RequestURITooLarge";
                case UnsupportedMediaType: return os << static_cast<int>(code) << " UnsupportedMediaType";
                case RequestedRangeNotSatisfiable: return os << static_cast<int>(code) << " RequestedRangeNotSatisfiable";
                case ExpectationFailed: return os << static_cast<int>(code) << " ExpectationFailed";
                case InternalServerError: return os << static_cast<int>(code) << " InternalServerError";
                case NotImplemented: return os << static_cast<int>(code) << " NotImplemented";
                case BadGateway: return os << static_cast<int>(code) << " BadGateway";
                case ServiceUnavailable: return os << static_cast<int>(code) << " ServiceUnavailable";
                case GatewayTimeOut: return os << static_cast<int>(code) << " GatewayTimeOut";
                case HTTPVersionNotSupported: return os << static_cast<int>(code) << " HTTPVersionNotSupported";
            }
            return os << "Unknown";
        }

    };
}

#endif //PROJECT_IHTTPRESPONSE_HPP
