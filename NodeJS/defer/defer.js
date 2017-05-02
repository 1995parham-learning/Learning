/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 02-05-2017
 * |
 * | File Name:     defer.js
 * +===============================================
 */
/* jshint esversion: 6 */


process.nextTick(() => console.log('tick tack'));

for (let i = 0; i < 10; i++) {
  console.log('Hello and How are you bro');
}
