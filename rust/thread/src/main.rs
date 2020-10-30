use std::thread;

fn main() {
    const THREAD_INDEX: u64 = 1;

    let th = thread::spawn(|| {
        println!("Hello World from {}", THREAD_INDEX);
        78
    });

    let result = th.join();
    match result {
        Ok(ret) => println!("Thread completed successfully with {}", ret),
        Err(_) => println!("Something went wrong"),
    }
}
