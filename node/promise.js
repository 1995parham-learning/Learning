/*
 *
 * In The Name of God
 *
 * +===============================================
 * | Author:        Parham Alvani <parham.alvani@gmail.com>
 * |
 * | Creation Date: 23-03-2021
 * |
 * | File Name:     promise.js
 * +===============================================
 */

// timeout is 300 millisecond
const timeout = 300;

function longCalculation(id) {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve(`resolved-${id}`);
    }, timeout);
  });
}

longCalculation(1)
  .then((result) => {
    console.log(`1st promise: ${result}`);
    return longCalculation(2);
  })
  .then((result) => {
    console.log(`2nd promise: ${result}`);
    return longCalculation(3);
  })
  .then((result) => {
    console.log(`3rd promise: ${result}`);
    return;
  });
