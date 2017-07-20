var counter = function (arr) {
    return 'there are ' + arr.length + ' elements in this array'
}

var adder = (a,b) => {
    return `the sum of the two integers is ${a+b}`
}

var pi = 3.14

module.exports = {
    counter: counter,
    adder: adder,
    pi: pi
}