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
        /* It's up to you
         * Setup your sockets and waits for clients
         */
        pollRequest();
    }

    void pollRequest() override {
        MyHttpResponse res;
        MyHttpRequest request;

        _pipelineRunCallBack(request, res);                                                                 //Run the processing list

        std::cout << static_cast<int>(res.getStatusCode()) << " " << res.getStatusMessage() << std::endl;   //The modules's response is : 200 OK
    }
};