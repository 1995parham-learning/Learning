use super::Fibonacci;

pub struct Recursive;

impl Fibonacci for &Recursive {
    fn fib(self, n: u64) -> u64 {
        if n == 0 || n == 1 {
            1
        } else {
            self.fib(n - 1) + self.fib(n - 2)
        }
    }
}

#[cfg(test)]
mod tests {
    use super::super::Fibonacci;
    use super::Recursive;

    macro_rules! fib_test {
        ($name:ident, $($i:expr, $e:expr),+) => {
            #[test]
            fn $name() {
                let r = Recursive;
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
