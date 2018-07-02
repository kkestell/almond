#include <cstdio>
#include "environment.hpp"

namespace almond
{
    Environment::Environment()
    {
        context.include(volume.load("/disk/main.wren"));
    }

    Environment::~Environment()
    {
    }

    std::unique_ptr<Response> Environment::request(std::unique_ptr<Request> req)
    {
        return context.request(std::move(req));
    }
}
