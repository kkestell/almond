#include "request.hpp"

namespace almond
{
    request::request(http::Request_ptr req)
    {
        path = req->uri().to_string();
        method = http::method::str(req->method()).to_string();
    }

    request::~request()
    {
    }
}
