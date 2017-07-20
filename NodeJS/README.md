# NodeJS

## V8 Engine
The engine that converts the javascript into the machine code.
* NodeJS is written in C++
* At the heart of the NodeJS is the V8 engine
* V8 Engine is embedded into the NodeJS

## Use the Node.js REPL shell
* Underscore is the result of the last operation.
* Spread Attributes: Spread attributes can be useful when you are building generic containers. However, they can also make your code messy by making it easy to pass a lot of irrelevant props to components that don't care about them.
```
function App1() {
  return <Greeting firstName="Ben" lastName="Hector" />;
}

function App2() {
  const props = {firstName: 'Ben', lastName: 'Hector'};
  return <Greeting {...props} />;
}
```
* Exit the current contenxt: 
```
.break
.clear
ctrl + c
```
* Save and Load sessions 
```
.save NAME.js
.load NAME.js
```

## Blocking and Non-Blocking Calls
The first example shows that the program blocks until it reads the file and then only it proceeds to end the program.
The second example shows that the program does not wait for file reading and proceeds to print "Program Ended" and at the same time, the program without blocking continues reading the file.
* Create a text file (.txt)
* Create the main.js
* Run the main.js

## Node Process Object
* Run the REPL Shell
* To see the global process: 
``` 
global.process              <--- Displays the global process
global.process.version      <--- Displays the node version
global.process.versions     <--- Displays the version of all dependencies in the node stack   
```

* Working with stdout and stdin
```
var stdTest = function(temp) {
  process.stdout.write(temp + '\n')
}

The above code is equal to console.log('');
```
* NextTick Callback: This will executes the code all the way down when it reaches the NextTick function. Nide is an event loop processor. It runs through in a loop looking for the events it can execute. It is similar to the **setTimeOut(function(){},0)** but there are no **IO Overheads** for that.

## Global Namespace
* Create the main.js(in directory)
* run the following in code console to pull those modules:
```
var modFoo = require('./main.js)    <--- Pull the modules inside
modFoo.setFoo(50)                   <--- Set the global variable
modFoo.returnFoo()                  <--- Return the global variable
```

## Global Buffer Object
The raw data coming from a tcp protocol or even a file system, is stored in an instance of the buffer class which is similar to an array of integers. Let's read a file from the file system and print out the contents of the buffer:
```
fs.readFile('input.txt', function(err, data) {      <--- Displays bullshit!
  console.log(data)
}) 

fs.readFile('input.txt', function(err, data) {      <--- Displays the text inside input.txt
  console.log(data.toString())
})

fs.readFile('input.txt', function(err, 'utf-8', data) {   <--- Displays the text inside input.txt with utf-8 encoding
  console.log(data.toString())
})
```
We can start creating a new buffer by using the following code:
```
buf = new Buffer(5)
buf.write('Hello World')
buf.toString()          <--- Displays 'Hello'

buf.write('hello', 2)   <--- Write from the offset 2
buf.toString()          <--- Displays 'hehel'

buf.write('xxxxx', 2, 1)   <--- Write from the offset 2 with length 1
buf.toString()          <--- Displays 'hexel'
```

Comparing the buffers:(compare or equals)
```
> buf1 = new Buffer('1234')
<Buffer 31 32 33 34>
> buf2 = new Buffer('0123')
<Buffer 30 31 32 33>
> buf1.compare(buf2)
// Returns 0
```
Sorting the buffer contents:
``` 
var arr = [buf1,buf2]
arr.sort(Buffer.compare)
```
Converting the buffer to JSON Object:
```
buf1.toJSON()
```
Creating a memory reference to the main buffer:
```
buf1 = new Buffer('Hello World!')
buf2 = bif1.slice(0,3)
buf2.toString()
```


## Modules
* Methods are not available to us outside the modules

**App.js**:
```
require('./count.js')

console.log(counter(['my', 'name', 'is', 'methoz']))
```

**count.js**:
```
var counter = function (arr) {
    return 'there are ' + arr.length + ' elements in this array'
}
```
But to make it available, we use **exports.module**.

**App.js**:
```
var whatever = require('./count.js')

console.log(whatever(['my', 'name', 'is', 'methoz']))
```

**count.js**:
```
var counter = function (arr) {
    return 'there are ' + arr.length + ' elements in this array'
}

module.exports = counter
```
### Template String and Backtick '`'
Embedding **variables** and **expression** without conceactinating them.

## Server
Whats important here is:
* Requests and their Headers
* Responses and their Headers
* Content-Type
* Status(200 Vs 404)
* Binding

```
var http = require('http')

var server = http.createServer(function(req, res) {
    
    /* Response Header */
    res.writeHead(200, {'Content-Type': 'text/plain'})
    res.end('Welcome!')
})
server.listen(3000, '127.0.0.1')
console.log('Listening to port 3000')
```

## Streams & Buffers
* Read about the candy mountain
* Transfer small chuncks of data at a time
* Data flows down the **Stream** into the **Buffer**

### Readable Streams
* Use **fs** module to read a file
* Create a readable stream using **createReadStream()**
* **createStream()** inherits from **EventEmitter**
* We also need to setup a listener for the readStream to fire up a function every time a chunk of data is loaded into the readStream.

### Writable Streams
* Use **fs** module to read a file
* Create a writable stream using **createWriteStream()**
* **createStream()** inherits from **EventEmitter**
* A place to write the files :)

### Pipes
* Taking the data from a WriteStream and piping that to a ReadStream
* **pipe** can be used on readable stream

### HTML Serving
* Change the text/plain to text/html
* Read the desired html page

### JSON Serving
* Change the text/plain to application/json
* Create an object 
* Send the object to the client using JSON.stringify(object)

## [promise](promise)
promise is a new way in node for handling callbacks, let's learn more about them with some example.

## [React](React)
React is a javascript library for building user interfaces, in this example we try to create minified
example of it.

## [request](request)
create http request to [varzesh3](http://www.varzesh3.com/) and save it contents using pipe into response.html.

## [async-flow](async-flow)
[co](https://github.com/tj/co), The ultimate generator based flow-control goodness for nodejs (supports thunks, promises, etc). in this example try to learn it.

## [await](await)
await-async is a new way in nodejs to simulate synchronous programming.

## [closure](closure)
a closure is a record storing a function[a] together with an environment.

## [defer](defer)
in nodejs you can defer execution of a function from main thread to event queue with `process.nextTick()`.

## [OO](OO)
Object Oriented design in javascript always is a problem for me, in this example I created some example for it.

## [chalk](chalk)
[chalk](https://github.com/chalk/chalk), Terminal string styling done right. in this example try to learn it.

## [Stream](stream)
1. readStdin: Read from stdin while not seeing EOF (ctrl + D) and create event on `process.stdin` readable stream.

## [Proxy](proxy)
A proxy is an object that controls access to another object, called subject.
