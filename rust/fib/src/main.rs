mod fib;

use fib::lin::Linear;
use fib::mem::Memorization;
use fib::Fibonacci;

fn main() {
    let mut n = String::new();

    std::io::stdin()
        .read_line(&mut n)
        .expect("cannot read n from command line");

    let n: u64 = n.trim().parse().expect("invalid number");

    let f = Linear;
    println!("{}", f.fib(n));

    let f = &mut Memorization::new();
    println!("{}", f.fib(n));
}
