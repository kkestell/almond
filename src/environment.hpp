#ifndef ALMOND_ENVIRONMENT_HPP
#define ALMOND_ENVIRONMENT_HPP

#include <memory>
#include <string>
#include "context.hpp"
#include "response.hpp"
#include "request.hpp"
#include "volume.hpp"

namespace almond
{
    class environment
    {
    private:
        context context;
        volume volume;
    public:
        environment();
        ~environment();
        std::unique_ptr<response> request(std::unique_ptr<almond::request> req);
    };
}

#endif
