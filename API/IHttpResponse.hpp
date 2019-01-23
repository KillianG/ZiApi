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
        enum StatusCode : int {
            UndefinedStatusCode = 0, Continue = 100, SwitchingProtocols = 101, OK = 200,
            Created = 201, Accepted = 202, NonAuthoritativeInformation = 203, NoContent = 204,
            ResetContent = 205, PartialContent = 206, MultipleChoices = 300, MovedPermanently = 301,
            Found = 302, SeeOther = 303, NotModified = 304, UseProxy = 305,
            TemporaryRedirect = 307, BadRequest = 400, Unauthorized = 401, PaymentRequired = 402,
            Forbidden = 403, NotFound = 404, MethodNotAllowed = 405, NotAcceptable = 406,
            ProxyAuthenticationRequired = 407, RequestTimeOut = 408, Conflict = 409, Gone = 410,
            LengthRequired = 411, PreconditionFailed = 412, RequestEntityTooLarge = 413, RequestURITooLarge = 414,
            UnsupportedMediaType = 415, RequestedRangeNotSatisfiable = 416, ExpectationFailed = 417, InternalServerError = 500,
            NotImplemented = 501, BadGateway = 502, ServiceUnavailable = 503, GatewayTimeOut = 504,
            HTTPVersionNotSupported = 505
        };

        static const std::string statusCodeToString(StatusCode code) {
            switch (code) {
                case (StatusCode::UndefinedStatusCode): return "UndefinedStatusCode";
                case (StatusCode::Continue): return "Continue";
                case (StatusCode::SwitchingProtocols): return "SwitchingProtocols";
                case (StatusCode::OK): return "OK";
                case (StatusCode::Created): return "Created";
                case (StatusCode::Accepted): return "Accepted";
                case (StatusCode::NonAuthoritativeInformation): return "NonAuthoritativeInformation";
                case (StatusCode::NoContent): return "NoContent";
                case (StatusCode::ResetContent): return "ResetContent";
                case (StatusCode::PartialContent): return "PartialContent";
                case (StatusCode::MultipleChoices): return "MultipleChoices";
                case (StatusCode::MovedPermanently): return "MovedPermanently";
                case (StatusCode::Found): return "Found";
                case (StatusCode::SeeOther): return "SeeOther";
                case (StatusCode::NotModified): return "NotModified";
                case (StatusCode::UseProxy): return "UseProxy";
                case (StatusCode::TemporaryRedirect): return "TemporaryRedirect";
                case (StatusCode::BadRequest): return "BadRequest";
                case (StatusCode::Unauthorized): return "Unauthorized";
                case (StatusCode::PaymentRequired): return "PaymentRequired";
                case (StatusCode::Forbidden): return "Forbidden";
                case (StatusCode::NotFound): return "Not found";
            }
        }
    };
}

#endif //PROJECT_IHTTPRESPONSE_HPP
