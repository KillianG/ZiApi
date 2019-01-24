#include <iostream>

#include <ZiLogger.hpp>
#include <AModule.hpp>
#include "IHttpResponse.hpp"

int main() {
    ZiApi::AModule A("/home","A");

    ZiApi::AModule B("/home", "B", 1, &A);
    ZiApi::AModule C("/home", "C", 3, &A, &B);
}