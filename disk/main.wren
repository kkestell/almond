class Routes {
  foreign static route(method, path, action)

  static routeDir(path) {
    var d = ""
    for(part in path.split("/")) {
      if(part != "" && !part.startsWith(":")) {
        d = d + "/" + part
      }
    }
    return d
  }

  static resources(path) {
    var routeDir = routeDir(path)

    Routes.route("get",    path,               "%(routeDir)/index")
    Routes.route("get",    "%(path)/:id",      "%(routeDir)/show")
    Routes.route("get",    "%(path)/:id/edit", "%(routeDir)/edit")
    Routes.route("patch",  "%(path)/:id",      "%(routeDir)/update")
    Routes.route("get",    "%(path)/new",      "%(routeDir)/new")
    Routes.route("post",   path,               "%(routeDir)/create")
    Routes.route("delete", "%(path)/:id",      "%(routeDir)/destroy")
  }

  static resource(path) {
    var routeDir = routeDir(path)

    Routes.route("get",    path,               "%(routeDir)/show")
    Routes.route("get",    "%(path)/edit",     "%(routeDir)/edit")
    Routes.route("patch",  "%(path)",          "%(routeDir)/update")
    Routes.route("get",    "%(path)/new",      "%(routeDir)/new")
    Routes.route("post",   path,               "%(routeDir)/create")
    Routes.route("delete", path,               "%(routeDir)/destroy")
  }
}

Routes.resources("/users")
Routes.resource("/users/:user_id/password")
