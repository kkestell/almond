#ifndef ALMOND_CONTEXT_HPP
#define ALMOND_CONTEXT_HPP

#include <net/http/response.hpp>
#include <net/http/request.hpp>
#include <string>
#include "response.hpp"
#include "request.hpp"
#include "wren.hpp"

namespace almond
{
    class Context
    {
    private:

    public:
        Context();
        ~Context();

        std::unique_ptr<Response> request(std::unique_ptr<Request> req);
    };
}

#endif
