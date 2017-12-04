#include <cstdio>
#include "environment.hpp"

environment::environment()
{
    this->context.expose("route", &environment::route, 2);

    this->context.include(volume.load("/disk/main.js"));
}

environment::~environment()
{
}

std::string environment::request()
{
    return this->context.request();
}

duk_ret_t environment::route(duk_context *ctx)
{
    auto name = std::string(duk_require_string(ctx, 0));
    auto idx = duk_require_int(ctx, 1);

    printf("%s %d\n", name.c_str(), idx);

    return 0;
}