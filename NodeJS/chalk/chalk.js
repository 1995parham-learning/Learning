/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 11-06-2017
 * |
 * | File Name:     chalk.js
 * +===============================================
 */
const chalk = require('chalk');

console.log(`${chalk.yellow('Hello')}`);
console.log(`${chalk.bgGreen('Hello')}`);
console.log(`${chalk.bgGreen(chalk.red('Hello'))}`);
