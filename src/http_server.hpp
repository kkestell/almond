#ifndef ALMOND_HTTP_SERVER_HPP
#define ALMOND_HTTP_SERVER_HPP

#include <memory>
#include <net/inet4>
#include <net/http/request.hpp>
#include <net/http/response.hpp>
#include <net/http/server.hpp>
#include "environment.hpp"

namespace almond
{
    class http_server
    {
    private:
        std::unique_ptr<http::Server> server;
        environment env;
    public:
        http_server();
        ~http_server();
    };
}

#endif
