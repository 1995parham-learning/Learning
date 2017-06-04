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
    Promise.resolve(2),
    Promise.resolve(3),
    (callback) => {
      callback(null, 4);
    }
  ];
  console.log(res);
}).then(() => {
  console.log('async flow was completed.');
});
