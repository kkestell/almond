#include <cstdio>
#include <functional>
#include <string>
#include "context.hpp"

static void fatal(void *udata, const char *msg) {
    fprintf(stderr, "FATAL: %s\n", (msg ? msg : "no message"));
    fflush(stderr);
    abort();
}

context::context()
{
    this->ctx = duk_create_heap(NULL, NULL, NULL, NULL, fatal);
}

context::~context()
{
    duk_destroy_heap(this->ctx);
}

void context::include(const std::string& buf)
{
    duk_eval_string(this->ctx, buf.c_str());
}

std::string context::request()
{
    duk_get_global_string(this->ctx, "request");
    duk_call(this->ctx, 0);
    std::string res = std::string(duk_require_string(this->ctx, -1));
    duk_pop(this->ctx);
    return res;
}

void context::expose(const std::string& name, duk_c_function func, int args)
{
    duk_push_global_object(this->ctx);
    duk_push_c_function(this->ctx, func, args);
    duk_put_prop_string(ctx, -2, name.c_str());
}
