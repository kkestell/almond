#include <net/http/request.hpp>
#include <net/http/response.hpp>
#include <string>
#include "context.hpp"
#include "volume.hpp"
#include "duk_config.h"
#include "duktape.h"

class environment
{
private:
    context context;
    volume volume;
    static duk_ret_t puts(duk_context *ctx);
public:
    environment();
    ~environment();
    std::string request(http::Request_ptr req);
};
