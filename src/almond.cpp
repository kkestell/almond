#include <cstdio>
#include <fstream>
#include <memdisk>
#include <os>
#include <service>
#include <fs/vfs.hpp>
#include "duk_config.h"
#include "duktape.h"

fs::Disk& memdisk()
{
    fs::Disk& disk = fs::memdisk();

    if (not disk.fs_ready()) {
        disk.init_fs([](fs::error_t err, auto&) {
            if (err)
                panic("error mounting disk\n");
        });
    }

    return disk;
}

void Service::start(const std::string& args)
{
    auto disk = memdisk().fs().stat("/");
    fs::mount("/memdisk", disk, "disk");

    duk_context *ctx = duk_create_heap_default();

    std::ifstream t("/memdisk/test.js");
    std::stringstream buffer;
    buffer << t.rdbuf();

    duk_eval_string(ctx, buffer.str().c_str());

    printf("%d\n", (int)duk_get_int(ctx, -1));

    duk_destroy_heap(ctx);
}
