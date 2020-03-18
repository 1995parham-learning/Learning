fn main() {
    println!("0: {}", fib(0));
    println!("1: {}", fib(1));
    println!("2: {}", fib(2));
    println!("3: {}", fib(3));
    println!("4: {}", fib(4));
}

fn fib(n: u32) -> u64 {
    let mut a = 1;
    let mut b = 1;

    for i in 2..=n {
        if i % 2 == 0 {
            a = a + b;
        } else {
            b = a + b;
        }
    }

    return if n % 2 == 0 {
        a
    } else {
        b
    }
}
