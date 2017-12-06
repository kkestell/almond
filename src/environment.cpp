#include <cstdio>
#include "environment.hpp"

namespace almond
{
    environment::environment()
    {
        context.expose("puts", &environment::puts, 1);

        context.include(volume.load("/disk/almond.js"));
        context.include(volume.load("/disk/main.js"));
    }

    environment::~environment()
    {
    }

    std::unique_ptr<response> environment::request(std::unique_ptr<almond::request> req)
    {
        return context.request(std::move(req));
    }

    duk_ret_t environment::puts(duk_context *ctx)
    {
        auto str = std::string(duk_require_string(ctx, 0));

        printf("%s\n", str.c_str());

        return 0;
    }
}
