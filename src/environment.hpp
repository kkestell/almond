#include "context.hpp"
#include "volume.hpp"

class environment
{
private:
    context context;
    volume volume;
public:
    environment();
    ~environment();
};
