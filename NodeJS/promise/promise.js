/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 30-05-2017
 * |
 * | File Name:     promise.js
 * +===============================================
 */
var p = new Promise((resolve, reject) => {
  resolve('fast resolve');
  console.log('we can create promise and resolve later')
});

p.then((msg) => {
  console.log(msg)
});
