var http = require('http')
var fs = require('fs')
var server = http.createServer(function (req, res) {

    /* Response Header */
    res.writeHead(200, { 'Content-Type': 'text/html' })
    /* Read the text when the request comes */
    var myReadStream = fs.createReadStream(__dirname + '/index.html','utf8')
    myReadStream.pipe(res)
})

server.listen(3000, '127.0.0.1')
console.log('Listening to port 3000')