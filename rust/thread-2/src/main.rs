use std::sync::Arc;

#[derive(Debug)]
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
        println!("person from the thread {:?}", q);
    });

    println!("person from the main {:?}", p);
    t.join().unwrap();

    println!(
        "number of references for person in main {}",
        Arc::strong_count(&p)
    );
}
