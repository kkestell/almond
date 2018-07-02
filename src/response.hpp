#ifndef ALMOND_RESPONSE_HPP
#define ALMOND_RESPONSE_HPP

#include <string>

namespace almond
{
    class Response
    {
    public:
        Response();
        ~Response();
        std::string body;
        std::string contentType;
    };
}

#endif
