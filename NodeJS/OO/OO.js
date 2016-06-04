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
"use strict";
/* Constructor Pattern */
function Person(name, age, work) {
	this.name = name;
	this.age = age;
	this.work = work;
	this.sayName = function() {
		return "My name is " + this.name;
	};
}
var p1 = new Person("Parham Alvani", 21, "Student");
console.log(p1.sayName());
console.log(typeof p1);

/* Constructor/Prototype Pattern */
function NewPerson(name, age, work) {
	this.name = name;
	this.age = age;
	this.work = work;
}

NewPerson.prototype = {
	constructor: NewPerson,
	sayName : function() {
		return "My name is " + this.name;
	}
}

var p2 = new NewPerson("Parham Alvani :)", 22, "Collegian");
console.log(p2.sayName());
console.log(typeof p2);


/* ECMAScript 6 Pattern */
class New6Person {
	constructor(name, age, work) {
		this._name = name;
		this._age = age;
		this._wotk = work;
	}
	get name() {
		return this._name;
	}
	get lastName() {
		return this._name.slice(this._name.indexOf(" ") + 1);
	}
	sayName() {
		return "My name is " + this.name;
	}
}

var p3 = new New6Person("Parham Alvani", 22, "Collegian");
console.log(p3.sayName());
console.log(p3.lastName);
console.log(typeof p3);

