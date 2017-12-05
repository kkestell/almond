get(/^\/$/i, function() {
  return 'Hello Almond!';
});

get(/^\/almonds$/i, function() {
  return '{ "almonds": [] }';
});