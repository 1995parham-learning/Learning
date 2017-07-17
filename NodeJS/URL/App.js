var url = require('url')
var address = 'https://www.motor1.com/'
var q = url.parse(address, true)

console.log(q.host)
console.log(q.pathname)
console.log(q.search)

var qdata = q.query
console.log(qdata)
