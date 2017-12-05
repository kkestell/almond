#include "http_server.hpp"

http_server::http_server() : env()
{
    auto& inet = net::Inet4::stack<0>();
    this->server = std::make_unique<http::Server>(inet.tcp());

    this->server->on_request([&] (auto req, auto rw) {
        rw->header().set_field(http::header::Server, "Almond/0.1");
        rw->header().set_field(http::header::Content_Type, "text/html; charset=UTF-8");
        rw->write(this->env.request(std::move(req)));
    });

    this->server->listen(80);
}

http_server::~http_server()
{
}