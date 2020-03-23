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

fn main() {
    let s1 = Student::new(String::from("Raha Dastan"), String::from("9631025"), 20);

    println!("Hello {} - {} - {}", s1.name, s1.id, s1.age);
}
