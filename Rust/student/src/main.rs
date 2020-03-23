use std::fmt;

struct Student {
    name: String,
    id: String,
    age: i32,
}

impl Student {
    fn new(name: String, id: String, age: i32) -> Box<Student> {
        Box::new(Student { name, id, age })
    }
}

impl fmt::Display for Student {
    fn fmt(self: &Self, formatter: &mut fmt::Formatter) -> fmt::Result {
        write!(formatter, "{} - {} - {}", self.name, self.id, self.age)
    }
}

fn main() {
    let s1 = Student::new(String::from("Raha Dastan"), String::from("9631025"), 20);

    println!("Hello {}", s1);
}
