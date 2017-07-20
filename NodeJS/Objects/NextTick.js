console.log('start')
process.nextTick(function() {
    console('We are in the nextTick callback :D')
})
console.log('finished')