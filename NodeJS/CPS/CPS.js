/*
 * In The Name Of God
 * ========================================
 * [] File Name : CPS.js
 *
 * [] Creation Date : 23-09-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
var fs = require('fs');
var content = ''
fs.readFile('/etc/passwd', function(err, fileContent) {
	if (err) {
		throw err;
	}
	content = fileContent.toString();
	console.log('passwd inner file content:\n', content);
});
console.log("I am here");
console.log('passwd outer file content:\n', content);
