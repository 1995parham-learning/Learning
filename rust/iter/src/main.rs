use std::collections::HashMap;
use std::iter::Iterator;

struct Counter {
    count: i32,
}

impl Counter {
    fn new() -> Self {
        Self { count: 0 }
    }
}

impl Iterator for Counter {
    type Item = i32;

    fn next(&mut self) -> Option<Self::Item> {
        if self.count == 5 {
            return None;
        }
        self.count += 1;
        Some(self.count)
    }
}

fn main() {
    let a = vec![1, 2, 3];

    let m: HashMap<&i32, i32> = a
        .iter()
        .map(|i| (i, 1))
        .inspect(|i| println!("({}, {})", i.0, i.1))
        .collect();

    println!("{}", m.keys().count());

    let name = "Elahe Dastan";

    name.chars()
        .map(|b| (b, 1))
        .for_each(|i| println!("({}, {})", i.0, i.1));

    let counter = Counter::new();
    println!("{}", counter.sum::<i32>());
}
