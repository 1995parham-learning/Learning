use std::collections::HashMap;

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
}
