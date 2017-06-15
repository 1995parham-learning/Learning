/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 15-06-2017
 * |
 * | File Name:     transform.js
 * +===============================================
 */
const stream = require('stream');

class ReplaceDash extends stream.Transform {
  constructor() {
    super();
  }

  _transform(chunk, encoding, callback) {
    const buff = Buffer.alloc(chunk.length, '-');
    buff[chunk.length - 1] = '\n';
    this.push(buff);
    callback();
  }

  _flush(callback) {
    callback();
  }
}

process.stdin.pipe(new ReplaceDash()).pipe(process.stdout)
