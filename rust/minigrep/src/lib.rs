use std::error::Error;
use std::{env, fs};

pub fn run(cfg: Config) -> Result<(), Box<dyn Error>> {
    let content = fs::read_to_string(cfg.filename)?;

    let results = if cfg.case_sensitive {
        search_case_insesitive(&cfg.query, &content)
    } else {
        search(&cfg.query, &content)
    };

    for line in results {
        println!("{}", line);
    }

    Ok(())
}

pub fn search<'a>(query: &str, content: &'a str) -> Vec<&'a str> {
    let mut results: Vec<&str> = vec![];

    for line in content.lines() {
        if line.contains(query) {
            results.push(line);
        }
    }

    results
}

pub fn search_case_insesitive<'a>(query: &str, content: &'a str) -> Vec<&'a str> {
    let query = query.to_lowercase();
    let mut results: Vec<&str> = vec![];

    for line in content.lines() {
        if line.to_lowercase().contains(&query) {
            results.push(line);
        }
    }

    results
}

pub struct Config {
    pub filename: String,
    pub query: String,
    pub case_sensitive: bool,
}

impl Config {
    pub fn new(args: &[String]) -> Result<Config, &'static str> {
        if args.len() < 3 {
            return Err("minigrep <query> <filename>");
        }

        let query = args[1].clone();
        let filename = args[2].clone();

        let case_sensitive = env::var("CASE_INSESITIVE").is_err();

        Ok(Config {
            filename,
            query,
            case_sensitive,
        })
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn case_sensitive() {
        let query = "duct";
        let content = "\
Rust:
safe, fast, productive.
Pick Three.
Duct Tape.";

        assert_eq!(vec!["safe, fast, productive."], search(query, content))
    }

    #[test]
    fn case_insesitive() {
        let query = "rUst";
        let content = "\
Rust:
safe, fast, productive.
Pick Three.
Trust me.";

        assert_eq!(
            vec!("Rust:", "Trust me."),
            search_case_insesitive(query, content)
        )
    }
}
