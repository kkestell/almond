#include <cstdio>
#include <string>
#include "context.hpp"

context::context()
{
    this->ctx = duk_create_heap_default();
}

context::~context()
{
    duk_destroy_heap(this->ctx);
}

void context::include(const std::string& buf)
{
    duk_eval_string(this->ctx, buf.c_str());
}