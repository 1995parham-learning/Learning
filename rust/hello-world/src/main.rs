use std::fmt;

#[derive(Debug)]
struct Person<T: AsRef<str>> {
    name: T,
    age: u8,
}

impl<T: AsRef<str> + std::fmt::Display> fmt::Display for Person<T> {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        return write!(
            f,
            "There is a person with name: {} and age {}",
            self.name, self.age
        );
    }
}

fn main() {
    println!("Hello, world!");

    let _h: &str = "Hello";

    // create a person using an &str
    let mut p = Person {
        name: "Parham Alvani",
        age: 25,
    };

    println!("{}", p);

    {
        let name: String = String::from("Elahe Dastan");
        p.name = name.as_str();

        println!("{}", p);
    }

    // uncomment the following line to get a nice compile error
    // because it __moves__ into inner context and name doesn't live
    // enough
    // println!("{}", p);

    let mut p = Person {
        name: String::from("Raha Dastan"),
        age: 23,
    };

    p.name.push('!');

    println!("{}", p);

    // learn about clourses
    let p = Person {
        name: "Parham Alvani",
        age: 25,
    };

    let parham_namer = || {
        println!("{}", p.name);
    };

    parham_namer();
    parham_namer();
}
