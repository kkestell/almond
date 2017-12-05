const routes = [];

function route(method, path, func) {
  routes.push({
    method: method,
    path: path,
    func: func
  });
}

function get(path, func) {
  route('GET', path, func);
}

function request(req) {
  puts(req.method + ' ' + req.path);
  for(var i = 0; i < routes.length; i++) {
    const route = routes[i];
    if(req.method === route.method && req.path.match(route.path))
      return route.func();
  };
  return 'Not Found';
}
