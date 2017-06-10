/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 02-05-2017
 * |
 * | File Name:     defer.js
 * +===============================================
 */
process.nextTick(() => console.log('-1. tick tack'));

for (let i = 0; i < 10; i++) {
  console.log(`${i}. Hello and How are you bro`);
  process.nextTick(() => console.log(`${i}. tick tack`));
}
