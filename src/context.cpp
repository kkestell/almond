#include <cstdio>
#include "context.hpp"

void write(WrenVM* vm, const char* text)
{
    printf(text);
}

namespace almond
{
    context::context()
    {
        WrenConfiguration config;
        wrenInitConfiguration(&config);

        config.writeFn = write;

        vm = wrenNewVM(&config);
    }

    context::~context()
    {
        wrenFreeVM(vm);
    }

    void context::include(const std::string& buf)
    {
        WrenInterpretResult result = wrenInterpret(vm, buf.c_str());
    }

    std::unique_ptr<response> context::request(std::unique_ptr<almond::request> req)
    {
        auto res = std::make_unique<response>();
        res->body = "Hello Almond!";
        res->content_type = "text/html";

        return res;
    }
}
