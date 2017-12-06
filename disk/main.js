get(/^\/$/i, function(req, res) {
  res.contentType = 'text/html; charset=utf-8';
  res.body = 'Hello Almond! ' + String.fromCharCode(0x1F44C);
});

get(/^\/almonds$/i, function(req, res) {
  res.contentType = 'application/json';
  res.body = JSON.stringify({ "almonds": [] });
});