/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 04-06-2017
 * |
 * | File Name:     generator.js
 * +===============================================
 */


function* fruitGenerator() {
  yield 'apple';
  yield 'orange';
  return 'watermelon';
}

const newFruitGenerator = fruitGenerator();
console.log(newFruitGenerator.next());
console.log(newFruitGenerator.next());
console.log(newFruitGenerator.next());

function* fibonacciGenerator() {
  let a = 1;
  let b = 1;
  let n = 1;

  while (true) {
    if (n % 2) {
      yield a;
      a = a + b;
      n++;
    } else {
      yield b;
      b = a + b;
      n++;
    }
  }
}

const newFibonacciGenerator = fibonacciGenerator();
for (let i = 0; i < 50; i++) {
  console.log(newFibonacciGenerator.next());
}
