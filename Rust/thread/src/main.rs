use std::thread;

fn main() {
    let th = thread::spawn(move || println!("Hello World"));

    let result = th.join();
    match result {
        Ok(_) => println!("Thread completed successfully"),
        Err(_) => println!("Something went wrong"),
    }
}
