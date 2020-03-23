fn main() {
    const N: usize = 3;

    let mut arr: [i32; N] = [0; N];

    for i in 1..=N {
        arr[i - 1] = i as i32
    }

    for ss in 0..(1 << N) {
        print!("{{");
        for i in 0..N {
            if ss & 1<<i != 0 {
                print!("{}", arr[i]);
            }
        }
        println!("}}");
    }
}
