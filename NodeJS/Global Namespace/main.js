var globalFoo;

exports.setFoo = function(val) {
    globalFoo = val;
}

exports.returnFoo = function() {
    return globalFoo;
}