#ifndef ALMOND_VOLUME_HPP
#define ALMOND_VOLUME_HPP

#include <fstream>
#include <fs/vfs.hpp>
#include <memdisk>
#include <os>
#include <string>

namespace almond
{
    class volume
    {
    private:
        fs::Dirent disk;
    public:
        volume();
        ~volume();
        std::string load(std::string filename);
    };
}

#endif
