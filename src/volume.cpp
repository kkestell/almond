#include "volume.hpp"

fs::Dirent make_disk()
{
    fs::Disk& disk = fs::memdisk();

    if (not disk.fs_ready()) {
        disk.init_fs([](fs::error_t err, auto&) {
            if (err) panic("error mounting disk\n");
        });
    }

    return disk.fs().stat("/");
}

volume::volume() : disk(make_disk())
{
    fs::mount("/disk", this->disk, "disk");
}

volume::~volume()
{
}

std::string volume::load(std::string filename)
{
    std::ifstream fp(filename);
    std::stringstream buf;
    buf << fp.rdbuf();
    return buf.str();
}