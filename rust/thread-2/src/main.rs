use std::sync::Arc;

struct Person {
    name: String,
    age: i32,
}

fn main() {
    // let mut board: [[i32; 4]; 4] = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]];
    let mut board: [[i32; 4]; 4] = [[0; 4]; 4];

    board[0][0] = 10;

    let p = Box::new(Person {
        name: "Elahe Dastan".to_owned(),
        age: 23,
    });
    let p = Arc::new(p);
    let q = p.clone();

    let t = std::thread::spawn(move || {
        println!(
            "number of references for person in thread {}",
            Arc::strong_count(&q)
        );
        println!("hello from {}({}) which is in the thread ", q.name, q.age);
    });

    println!("hello from {}({}) which is in the main", p.name, p.age);
    t.join().unwrap();

    println!(
        "number of references for person in main {}",
        Arc::strong_count(&p)
    );
}
