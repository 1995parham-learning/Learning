use std::{env, fs, process};

fn main() {
    let args: Vec<String> = env::args().collect();

    let config = Config::new(&args).unwrap_or_else(|err| {
        println!("problem parsing arguments: {}", err);
        process::exit(1);
    });

    let content = fs::read_to_string(config.filename).unwrap_or_else(|err| {
        println!("failed to read: {}", err);
        process::exit(1);
    });
    println!("{}", content);
}

struct Config {
    filename: String,
    query: String,
}

impl Config {
    fn new(args: &[String]) -> Result<Config, &'static str> {
        if args.len() < 3 {
            return Err("minigrep <query> <filename>");
        }

        let query = args[1].clone();
        let filename = args[2].clone();

        Ok(Config { query, filename })
    }
}
