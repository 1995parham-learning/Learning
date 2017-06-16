/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 04-06-2017
 * |
 * | File Name:     generator.js
 * +===============================================
 */

/* Generators + :) */

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

/* Asynchronous control flow with generators */

function asyncFlow(generatorFunction) {
  function callback(err) {
    if (err) {
      return generator.throw(err);
    }
    const results = [].slice.call(arguments, 1);
    generator.next(results.length > 1 ? results : results[0]);
  }
  const generator = generatorFunction(callback);
  generator.next();
}

asyncFlow(function* (callback) {
  console.log('1. Hello');
  yield setTimeout(callback, 2000);
  console.log('2. 2000ms');
  yield setTimeout(callback, 1000);
  console.log('3. 1000ms');
});
