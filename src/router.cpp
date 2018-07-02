#include "router.hpp"

namespace almond
{
  Router::Router()
  {
  }

  Router::~Router()
  {
  }

  void Router::add(std::string method, std::string path, std::string action)
  {
    routes.push_back(std::make_unique<Route>(method, path, action));
  }

  std::string Router::match(std::string method, std::string path)
  {
    return routes.front()->action;
  }
}