#ifndef ALMOND_HTTP_SERVER_HPP
#define ALMOND_HTTP_SERVER_HPP

#include <memory>
#include <net/inet4>
#include <net/http/request.hpp>
#include <net/http/response.hpp>
#include <net/http/server.hpp>
#include "environment.hpp"
#include "router.hpp"

namespace almond
{
    class HttpServer
    {
    private:
        std::unique_ptr<http::Server> server;
        Environment environment;
        Router router;
    public:
        HttpServer();
        ~HttpServer();
    };
}

#endif
