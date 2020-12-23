pub mod lin;
pub mod mem;
pub mod rec;

pub trait Fibonacci {
    fn fib(self, n: u64) -> u64;
}
