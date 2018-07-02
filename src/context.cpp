#include <cstdio>
#include "context.hpp"

void write(WrenVM* vm, const char* text)
{
    printf(text);
}

void error(
  WrenVM* vm,
  WrenErrorType type,
  const char* module,
  int line,
  const char* message)
{
    printf("%d %s %d %s %s", type, module, line, message);
}

void route(WrenVM* vm)
{
  const char* method = wrenGetSlotString(vm, 1);
  const char* path = wrenGetSlotString(vm, 2);
  const char* action = wrenGetSlotString(vm, 3);

  printf("%s %s => %s\n", method, path, action);
}

WrenForeignMethodFn bindForeignMethod(
  WrenVM* vm,
  const char* module,
  const char* className,
  bool isStatic,
  const char* signature)
{
  if(strcmp("route(_,_,_)", signature) == 0) {
    return route;
  }
}

namespace almond
{
    Context::Context()
    {
        WrenConfiguration config;
        wrenInitConfiguration(&config);

        config.writeFn = write;
        config.errorFn = error;
        config.bindForeignMethodFn = bindForeignMethod;

        vm = wrenNewVM(&config);
    }

    Context::~Context()
    {
        wrenFreeVM(vm);
    }

    void Context::include(const std::string& buf)
    {
        WrenInterpretResult result = wrenInterpret(vm, buf.c_str());
    }

    std::unique_ptr<Response> Context::request(std::unique_ptr<Request> req)
    {
        auto res = std::make_unique<Response>();
        res->body = "Hello Almond!";
        res->contentType = "text/html";
        return res;
    }
}
