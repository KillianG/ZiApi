//
// Created by nhyarlathotep on 31/01/19.
//

#pragma once

#include <iostream>
#include "Network.hpp"

#include "MyHttpRequest.hpp"
#include "MyHttpResponse.hpp"

class MyNetwork : public ZiApi::Network {
public:
    void run() override {
        MyHttpResponse res;
        MyHttpRequest request;
        _pipelineRunCallBack(request, res);                                                                 //Run the processing list

        std::cout << static_cast<int>(res.getStatusCode()) << " " << res.getStatusMessage() << std::endl;   //200 OK
    }

    void pollRequest() override {}
};