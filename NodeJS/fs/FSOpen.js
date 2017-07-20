var fs = require('fs');

fs.open('readme2.txt', 'w', function(err, file){
    if (err) throw err;
    console.log('Done opening the file for writing.')
})