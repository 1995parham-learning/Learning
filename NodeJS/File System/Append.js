var fs = require('fs');

fs.appendFile('readme.txt', 'Hello Ali :D', function(err) {
    if(err) 
        throw err;
    console.log('saved!');
});