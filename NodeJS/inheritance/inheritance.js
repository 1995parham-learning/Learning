/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 29-04-2016
 * |
 * | File Name:     inheritance.js
 * +===============================================
 */
function SuperType(name) {
	this.name = name;
	this.colors = ["red", "blue", "green"];
}

SuperType.prototype.sayName = function() {
	console.log(this.name);
};

function SubType(name, age) {
	// inherit properties
	SuperType.call(this, name);
	
	this.age = age;
}

SubType.prototype = new SuperType();

SubType.prototype.sayAge = function() {
	console.log(this.age);
};

console.log(SubType.prototype);

var instance1 = new SubType("Parham", 18);
instance1.colors.push("orange");
console.log(instance1.colors);
instance1.sayName();
instance1.sayAge();
