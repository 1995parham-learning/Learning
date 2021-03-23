/*
 *
 * In The Name of God
 *
 * +===============================================
 * | Author:        Parham Alvani <parham.alvani@gmail.com>
 * |
 * | Creation Date: 23-03-2021
 * |
 * | File Name:     call-by-value.js
 * +===============================================
 */

function changeMe(value) {
  value = 10;
}

function changePropertyInMe(value) {
  value.x = 20;
}

point = { x: 10, y: 10, toString: () => console.log(`(${this.x}, ${this.y})`) };

console.log(point);

changeMe(point);

console.log(point);

changePropertyInMe(point);

console.log(point);
