/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 11-06-2017
 * |
 * | File Name:     readStdin.js
 * +===============================================
 */

process.stdin.on('readable', () => {
  let chunk;
  console.log('New data available');
  while ((chunk = process.stdin.read()) !== null) {
    console.log(
      `Chunk read: (${chunk.length}) "${chunk.toString()}"`
    );
  }
})
  .on('end', () => process.stdout.write('End of stream'));
