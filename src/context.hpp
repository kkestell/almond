#ifndef ALMOND_CONTEXT_HPP
#define ALMOND_CONTEXT_HPP

#include <net/http/response.hpp>
#include <net/http/request.hpp>
#include <string>
#include "duk_config.h"
#include "duktape.h"
#include "response.hpp"
#include "request.hpp"

namespace almond
{
    class context
    {
    private:
        duk_context* ctx;
    public:
        context();
        ~context();
        void include(const std::string& buf);
        std::unique_ptr<response> request(std::unique_ptr<request> req);
        void expose(const std::string& name, duk_c_function func, int args);
    };
}

#endif
