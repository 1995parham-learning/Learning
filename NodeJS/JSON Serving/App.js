var http = require('http')
var fs = require('fs')
var server = http.createServer(function (req, res) {

    /* Response Header */
    res.writeHead(200, { 'Content-Type': 'application/json' })
    var jsonObjcet = {
        name: 'Ali Gholami',
        age: '21'
    }
    res.end(JSON.stringify(jsonObjcet))
})

server.listen(3000, '127.0.0.1')
console.log('Listening to port 3000')