#ifndef ALMOND_REQUEST_HPP
#define ALMOND_REQUEST_HPP

#include <net/http/request.hpp>
#include <string>

namespace almond
{
    class request
    {
    public:
        request(http::Request_ptr);
        ~request();
        std::string path;
        std::string method;
    };
}

#endif
