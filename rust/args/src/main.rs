fn main() {
    let args: Vec<u64> = std::env::args()
        .skip(1)
        .map(|arg| arg.parse::<u64>().expect("invalid argument"))
        .collect();

    println!("{:?}", args);
}
