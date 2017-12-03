#include <string>
#include "duk_config.h"
#include "duktape.h"
#include "dukglue.h"

class context
{
private:
    duk_context* ctx;
public:
    context();
    ~context();
    void include(const std::string& buf);
};
