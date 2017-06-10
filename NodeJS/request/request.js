var http = require('http');
var fs = require('fs');


/* Get request to varzesh3 based on pipes */
http.get("http://www.varzesh3.com/", function(response) {
  console.log("Got response: " + response.statusCode);

  var ws = fs.createWriteStream('response.html');
  response.pipe(ws);

  /* Listen for end of file event of res */
  response.on('end', function(){
    console.log('Finished !');
  });

  /* Listen for error event of http get */
}).on('error', function(e) {
  console.log("Got error: " + e.message);
});
