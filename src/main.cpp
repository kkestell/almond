#include <service>
#include "http_server.hpp"

void Service::start(const std::string& args)
{
    const auto& server = new http_server();
}
