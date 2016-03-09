/*
 * In The Name Of God
 * ========================================
 * [] File Name : OO.js
 *
 * [] Creation Date : 25-09-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
/* Constructor Pattern */
function Person(name, age, work) {
	this.name = name;
	this.age = age;
	this.work = work;
	this.sayName = function() {
		return "My name is " + this.name;
	};
}
p1 = new Person("Parham Alvani", 21, "Student");
console.log(p1.sayName());

/* Constructor/Prototype Pattern */
function NewPerson(name, age, work) {
	this.name = name;
	this.age = age;
	this.work = work;
}

NewPerson.prototype = {
	constructor: Person,
	sayName : function() {
		return "My name is " + this.name;
	}
}

p2 = new NewPerson("Parham Alvani :)", 22, "Collegian");
console.log(p2.sayName());
