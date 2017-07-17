var fs = require('fs');

fs.unlink('readme2.txt', function(err) {
    if(err)
        throw err;
    console.log('file deleted!');
})