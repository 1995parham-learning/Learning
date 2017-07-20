    var http = require('http')
    var fs = require('fs')

    var myReadStream = fs.createReadStream(__dirname + '/readme.txt',{encoding: 'utf8'})
    var myWriteStream = fs.createWriteStream(__dirname, '/writtenText.txt',{encoding: 'utf8'})

    /* The event name is called data */
    myReadStream.on('data', function(chunk){
        myWriteStream.write(chunk)
    })
