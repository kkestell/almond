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

function request(req, res) {
  // puts(req.method + ' ' + req.path);

  for(var i = 0; i < routes.length; i++) {
    const route = routes[i];
    if(req.method === route.method && req.path.match(route.path)) {
      route.func(req, res);
      return res;
    }
  };

  res.contentType = 'text/html; charset=utf-8'
  res.body = '<h1>Not Found</h1>'

  return res;
}
