fn main() {
    println!("gcd(10, 2) = {}", gcd(10, 2));
    println!("gcd(2, 10) = {}", gcd(10, 2));
    println!("gcd(15, 10) = {}", gcd(10, 2));
}

fn gcd(a: u32, b: u32) -> u32 {
    if a % b == 0 {
        b
    } else {
        gcd(b, a % b)
    }
}
