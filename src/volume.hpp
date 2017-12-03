#include <fstream>
#include <fs/vfs.hpp>
#include <memdisk>
#include <memory>
#include <os>
#include <string>

class volume
{
private:
    fs::Dirent disk;
public:
    volume();
    ~volume();
    std::string load(std::string filename);
};
