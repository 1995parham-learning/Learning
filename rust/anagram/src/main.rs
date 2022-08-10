use std::collections::{HashMap, HashSet};

fn main() {
    let parham = "parham";
    let hampar = "hampar";

    let result: HashSet<&str>;

    {
        let s = [parham, hampar, "123"];

        result = anagrams_for("parham", &s);
    }

    for a in result {
        println!("{}", a);
    }
}

fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let mut s: HashSet<&str> = HashSet::new();

    for &p in possible_anagrams.iter() {
        if word.to_lowercase() == p.to_lowercase() {
            continue;
        }
        if is_anagram(word, p) {
            s.insert(p);
        }
    }

    s
}

fn is_anagram(word: &str, possible_anagram: &str) -> bool {
    let mut characters: HashMap<char, i32> = HashMap::new();

    for b in word.to_lowercase().chars() {
        characters.insert(b, *characters.get(&b).unwrap_or(&0) + 1);
    }

    for b in possible_anagram.to_lowercase().chars() {
        characters.insert(b, *characters.get(&b).unwrap_or(&0) - 1);
    }

    for &v in characters.values() {
        if v != 0 {
            return false;
        }
    }

    true
}

#[cfg(test)]
mod tests {
    use super::is_anagram;

    macro_rules! is_anagram_test {
        ($name:ident, $($input:expr, $anagram:expr, $expect:expr),+) => {
            #[test]
            fn $name() {
                $({
                    assert_eq!(is_anagram($input, $anagram), $expect);
                })*
            }
        }
    }

    is_anagram_test!(with_parham_1, "parham", "parham", true);
    is_anagram_test!(with_parham_2, "parham", "arpmha", true);
    is_anagram_test!(with_numbers_3, "321", "123", true);
    is_anagram_test!(with_numbers_4, "321", "1234", false);
    is_anagram_test!(with_elahe, "elahe", "elahes", false);
}
