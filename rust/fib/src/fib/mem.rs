use super::rec::Recursive;
use super::Fibonacci;
use std::collections::HashMap;

pub struct Memorization {
    cacher: Cacher<fn(u64) -> u64>,
}

impl Memorization {
    pub fn new() -> Memorization {
        Memorization {
            cacher: Cacher::new(Self::_fib),
        }
    }

    fn _fib(n: u64) -> u64 {
        let r = Recursive;

        r.fib(n)
    }
}

impl Fibonacci for &mut Memorization {
    fn fib(self, n: u64) -> u64 {
        self.cacher.value(n)
    }
}

struct Cacher<T>
where
    T: Fn(u64) -> u64,
{
    values: HashMap<u64, u64>,
    fun: T,
}

impl<T> Cacher<T>
where
    T: Fn(u64) -> u64,
{
    fn new(fun: T) -> Cacher<T> {
        Cacher {
            values: HashMap::new(),
            fun,
        }
    }

    fn value(&mut self, arg: u64) -> u64 {
        match self.values.get(&arg) {
            Some(&v) => v,
            None => {
                let v = (self.fun)(arg);
                self.values.insert(arg, v);
                v
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::super::Fibonacci;
    use super::Memorization;

    macro_rules! fib_test {
        ($name:ident, $($i:expr, $e:expr),+) => {
            #[test]
            fn $name() {
                let r = &mut Memorization::new();
                $({
                    let o = r.fib($i);
                    assert_eq!(o, $e);
                })*
            }
        }
    }

    fib_test!(zero, 0, 1);
    fib_test!(one, 1, 1);
    fib_test!(two, 2, 2);
    fib_test!(three, 3, 3);
}
