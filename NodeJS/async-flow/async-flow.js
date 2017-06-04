/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 04-06-2017
 * |
 * | File Name:     async-flow.js
 * +===============================================
 */
const co = require('co');


co(function* () {
  var res = yield [
    Promise.resolve(1),
    new Promise(resolve => {
      setTimeout(() => {
        console.log('2');
        resolve(2);
      }, 10);
    }),
    /* Promise */
    Promise.resolve(3),
    /* Thunk */
    (callback) => {
      setTimeout(() => {
        console.log('4');
        callback(null, 4);
      }, 5);
    }
  ];
  yield function* () {
    console.log('5');
    yield Promise.resolve(5);
  }();
  console.log(res);
}).then(() => {
  console.log('async flow was completed.');
});
