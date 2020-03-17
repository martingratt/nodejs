var http = require('http');
var dt = require('./Modules/myfirstmodule');

http.createServer(function (req, res) {
    res.writeHead(200, {'Content-Type': 'text/plain'});
    res.write("The time is: " +dt.myDateTime());
    res.end('Hello World!');
}).listen(8080);
