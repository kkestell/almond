#include "volume.hpp"

fs::Dirent makeDisk()
{
    fs::Disk& disk = fs::memdisk();

    if (not disk.fs_ready()) {
        disk.init_fs([](fs::error_t err, auto&) {
            if (err) panic("error mounting disk\n");
        });
    }

    return disk.fs().stat("/");
}

namespace almond
{
    Volume::Volume() : disk(makeDisk())
    {
        fs::mount("/disk", disk, "disk");
    }

    Volume::~Volume()
    {
    }

    std::string Volume::load(std::string filename)
    {
        const std::ifstream fp(filename);
        std::stringstream buf;
        buf << fp.rdbuf();
        return buf.str();
    }
}