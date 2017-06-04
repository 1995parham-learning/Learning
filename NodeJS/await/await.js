/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 04-06-2017
 * |
 * | File Name:     await.js
 * +===============================================
 */

function doProcess(number) {
  return new Promise(resolve => {
    setTimeout(() => {
      resolve(number);
    }, 10);
  });
}

async function main() {
  number = await doProcess(10);
  console.log(number);
}

main();
console.log('loading ...');
