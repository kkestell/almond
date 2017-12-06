#include "http_server.hpp"

namespace almond
{
    http_server::http_server() : env()
    {
        auto& inet = net::Inet4::stack<0>();
        server = std::make_unique<http::Server>(inet.tcp());

        server->on_request([&](auto req, auto res) {
            res->header().set_field(http::header::Server, "Almond/0.1");

            auto request = std::make_unique<almond::request>(std::move(req));
            auto response = env.request(std::move(request));

            res->header().set_field(http::header::Content_Type, response->content_type);
            res->write(response->body);
        });

        server->listen(80);
    }

    http_server::~http_server()
    {
    }
}
