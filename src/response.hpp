#ifndef ALMOND_RESPONSE_HPP
#define ALMOND_RESPONSE_HPP

#include <string>

namespace almond
{
    class response
    {
    public:
        response();
        ~response();
        std::string body;
        std::string content_type;
    };
}

#endif
