#ifndef ALMOND_VOLUME_HPP
#define ALMOND_VOLUME_HPP

#include <fstream>
#include <fs/vfs.hpp>
#include <memdisk>
#include <os>
#include <string>

namespace almond
{
    class Volume
    {
    private:
        fs::Dirent disk;
    public:
        Volume();
        ~Volume();
        std::string load(std::string filename);
    };
}

#endif
