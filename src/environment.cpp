#include <cstdio>
#include "environment.hpp"

environment::environment() : context(), volume()
{
    context.include(volume.load("/memdisk/test.js"));
}

environment::~environment()
{
}

