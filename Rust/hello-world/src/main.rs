use std::fmt;

#[derive(Debug)]
struct Person<'a> {
    name: &'a str,
    age: u8
}

impl<'a> fmt::Display for Person<'a> {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        return write!(f, "There is a person with name: {} and age {}", self.name, self.age);
    }
}

fn main() {
    println!("Hello, world!");

    let p = Person{ name: "Parham Alvani", age: 25 };
    println!("{}", p);
}
