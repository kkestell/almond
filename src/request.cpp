#include "request.hpp"

namespace almond
{
    Request::Request(http::Request_ptr req)
    {
        path = req->uri().to_string();
        method = http::method::str(req->method()).to_string();
    }

    Request::~Request()
    {
    }
}
