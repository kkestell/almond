#include <service>
#include <cstdio>
#include "luajit.h"

void Service::start(const std::string& args)
{
    printf("%s\n", LUAJIT_VERSION);
}
