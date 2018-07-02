#ifndef ALMOND_ROUTER_HPP
#define ALMOND_ROUTER_HPP

#include <string>
#include <vector>

namespace almond
{
  struct Route
  {
    Route(std::string m, std::string p, std::string a) :
      method(m),
      path(p),
      action(a)
    {
    }

    std::string method;
    std::string path;
    std::string action;
  };

  class Router
  {
  private:
    std::vector<std::unique_ptr<Route>> routes;
  public:
    Router();
    ~Router();
    void add(std::string method, std::string path, std::string action);
    std::string match(std::string method, std::string path);
  };
}

#endif
