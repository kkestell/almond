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
    class context
    {
    private:
        WrenVM* vm;
    public:
        context();
        ~context();
        void include(const std::string& buf);
        std::unique_ptr<response> request(std::unique_ptr<request> req);
    };
}

#endif
