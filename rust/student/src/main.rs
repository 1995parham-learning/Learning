use std::fmt;

struct Student {
    name: String,
    id: String,
    age: i32,
}

impl Student {
    fn new(name: String, id: String, age: i32) -> Student {
        Student { name, id, age }
    }
}

impl fmt::Display for Student {
    fn fmt(&self, formatter: &mut fmt::Formatter) -> fmt::Result {
        write!(formatter, "{} - {} - {}", self.name, self.id, self.age)
    }
}

fn main() {
    let mut s1 = Student::new(String::from("Raha Dastan"), String::from("9631025"), 20);

    // borrow mutable reference from a mutable variable
    let r1 = &mut s1;

    // here you cannot borrow s1 because there is a mutable reference
    // exists from s1.

    println!("Hello Reference {:p}", r1);
    println!("Hello {}", s1);

    let i: &i32 = &10;

    // use pointer formatter for printing the reference address
    println!("i: {:p}", i);
    println!("*i: {}", *i);
}
