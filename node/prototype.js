/*
 *
 * In The Name of God
 *
 * +===============================================
 * | Author:        Parham Alvani <parham.alvani@gmail.com>
 * |
 * | Creation Date: 23-03-2021
 * |
 * | File Name:     prototype.js
 * +===============================================
 */

// here we are going to use the Object.create to provide
// our prototype to an object.

// Person is our portotype
let Person = {
  _name: "",
  _family: "",

  get name() {
    return this._name;
  },

  get family() {
    return this._family;
  },

  set name(name) {
    this._name = name;
  },

  set family(family) {
    this._family = family;
  },
};

// p1 is an instance based on Person prototype
let p1 = Object.create(Person);

p1.name = "Parham";
p1.family = "Alvani";

console.log(p1.name, p1.family);

// the old way, using function as constructor

function Student(name, id) {
  this.name = name;
  this.id = id;

  this.toString = function () {
    return `${this.name}: ${this.id}`;
  };
}

let s1 = new Student("Parham Alvani", "9231058");
console.log(s1.toString());
