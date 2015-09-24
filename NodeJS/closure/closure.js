/*
 * In The Name Of God
 * ========================================
 * [] File Name : closure.js
 *
 * [] Creation Date : 23-09-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
function Circle(r) {
	
	function area() {
		return r * r * 3.14;
	}
	
	return {
		'area': area,
		'radius': r
	};
}

c = Circle(10);
console.log(c);
console.log(c.area());
console.log(c.radius);
