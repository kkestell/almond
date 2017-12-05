#include <cstdio>
#include "environment.hpp"

environment::environment()
{
    this->context.expose("puts", &environment::puts, 1);

    this->context.include(volume.load("/disk/almond.js"));
    this->context.include(volume.load("/disk/main.js"));
}

environment::~environment()
{
}

std::string environment::request(http::Request_ptr req)
{
    return this->context.request(std::move(req));
}

duk_ret_t environment::puts(duk_context *ctx)
{
    auto str = std::string(duk_require_string(ctx, 0));

    printf("%s\n", str.c_str());

    return 0;
}