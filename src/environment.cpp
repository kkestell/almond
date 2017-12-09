#include <cstdio>
#include "environment.hpp"

namespace almond
{
    environment::environment()
    {
        context.include(volume.load("/disk/main.wren"));
    }

    environment::~environment()
    {
    }

    std::unique_ptr<response> environment::request(std::unique_ptr<almond::request> req)
    {
        return context.request(std::move(req));
    }
}
