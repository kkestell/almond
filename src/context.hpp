#include <functional>
#include <string>
#include "duk_config.h"
#include "duktape.h"

class context
{
private:
    duk_context* ctx;
public:
    context();
    ~context();
    void include(const std::string& buf);
    std::string request();
    void expose(const std::string& name, duk_c_function func, int args);
};
