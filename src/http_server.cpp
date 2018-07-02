#include "http_server.hpp"

namespace almond
{
    HttpServer::HttpServer() : environment(), router()
    {
        auto& inet = net::Inet4::stack<0>();
        server = std::make_unique<http::Server>(inet.tcp());

        server->on_request([&](auto req, auto res) {
            res->header().set_field(http::header::Server, "Almond/0.1");

            //auto request = std::make_unique<Request>(std::move(req));
            //auto response = environment.request(std::move(request));

            //res->header().set_field(http::header::Content_Type, response->contentType);
            //res->write(response->body);

            res->header().set_field(http::header::Content_Type, "text/html");
            res->write(
              router.match(
                http::method::str(req->method()).to_string(),
                req->uri().to_string()
              )
            );
        });

        server->listen(80);
    }

    HttpServer::~HttpServer()
    {
    }
}
