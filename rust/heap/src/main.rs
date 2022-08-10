fn main() {
    let a = Box::new(1);
    let b = Box::new(2);
    let c = Box::new(3);

    let r1 = *a + *b + *c;

    println!("&a = {:p}", a);
    println!("&b = {:p}", b);
    println!("&c = {:p}", c);

    drop(a);

    let d = Box::new(1);

    let r2 = *b + *c + *d;

    println!("&d = {:p}", d);

    println!("r1 = {}\nr2 = {}", r1, r2);
}
