#ifndef ALMOND_REQUEST_HPP
#define ALMOND_REQUEST_HPP

#include <net/http/request.hpp>
#include <string>

namespace almond
{
    class Request
    {
    public:
        Request(http::Request_ptr);
        ~Request();
        std::string path;
        std::string method;
    };
}

#endif
