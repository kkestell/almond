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
    class Environment
    {
    private:
        WrenVM* vm;
        Context context;
        Volume volume;
    public:
        Environment();
        ~Environment();
        std::unique_ptr<Response> request(std::unique_ptr<Request> req);
    };
}

#endif
