fn main() {
    for i in 0..10 {
        println!("{}: {}", i, fib(i));
    }
}

fn fib(n: u32) -> u64 {
    let mut a = 1;
    let mut b = 1;

    for i in 2..=n {
        if i % 2 == 0 {
            a += b;
        } else {
            b += a;
        }
    }

    if n % 2 == 0 {
        a
    } else {
        b
    }
}
