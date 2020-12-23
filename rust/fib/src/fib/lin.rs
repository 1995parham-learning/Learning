use super::Fibonacci;

pub struct Linear;

impl Fibonacci for &Linear {
    fn fib(self, n: u64) -> u64 {
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
}

#[cfg(test)]
mod tests {
    use super::super::Fibonacci;
    use super::Linear;

    macro_rules! fib_test {
        ($name:ident, $($i:expr, $e:expr),+) => {
            #[test]
            fn $name() {
                let l = Linear;
                $({
                    let o = l.fib($i);
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
