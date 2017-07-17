var http = require('http');
var fs = require('fs');

http.createServer(function(req, res){
    fs.readFile('index.html','utf8', function(err, data) {
        res.writeHead(200, {'Content-Type': 'text/html'});
        res.write(data)
        res.end('finished :D');
    });
}).listen(3000)
