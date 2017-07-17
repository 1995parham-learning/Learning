var http = require('http')
var fs = require('fs')

var myReadStream = fs.createReadStream(__dirname + '/readme.txt','utf8')

/* The event name is called data */
myReadStream.on('data', function(chunk){
    console.log('new chunk recieved: ')
    console.log(chunk)
})