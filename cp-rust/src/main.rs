#![allow(unused_variables, unused_imports, dead_code)]
/*
    Author: Manash Baul <mximpaid@gmail.com>
    Comment: The deeper you go, the more still you become.
*/
use std::cmp::{max, min};
use std::collections::{BTreeMap, BTreeSet, HashMap, HashSet, VecDeque};
use std::env;
use std::fs::File;
use std::io::{self, BufRead, BufReader, BufWriter, Stdin, Write};
use std::str::FromStr;

const INF: i32 = 1e9 as i32;

enum InputSource {
    File(std::io::Lines<BufReader<File>>),
    Stdin(std::io::Lines<BufReader<Stdin>>),
}

struct InputReader {
    source: InputSource,
}

impl InputReader {
    fn new() -> InputReader {
        // Check if running in a local environment
        let local = env::var("LOCAL").is_ok();

        let source = if local {
            const FILE_PATH: &str = "/Users/fenwick/CP-SETUP/input.txt";
            let file = File::open(FILE_PATH).expect("Unable to open file");
            InputSource::File(BufReader::new(file).lines())
        } else {
            InputSource::Stdin(BufReader::new(io::stdin()).lines())
        };

        InputReader { source }
    }

    fn next<T: FromStr>(&mut self) -> T
    where
        <T as FromStr>::Err: std::fmt::Debug,
    {
        match &mut self.source {
            InputSource::File(lines) => lines.next().unwrap().unwrap().trim().parse().unwrap(),
            InputSource::Stdin(lines) => lines.next().unwrap().unwrap().trim().parse().unwrap(),
        }
    }

    fn next_vec<T: FromStr>(&mut self) -> Vec<T>
    where
        <T as FromStr>::Err: std::fmt::Debug,
    {
        match &mut self.source {
            InputSource::File(lines) => lines
                .next()
                .unwrap()
                .unwrap()
                .split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect(),
            InputSource::Stdin(lines) => lines
                .next()
                .unwrap()
                .unwrap()
                .split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect(),
        }
    }
}

struct ComputeSet {
    storage: HashMap<i32, i64>,
    result: i64,
}
fn main() {
    let mut input = InputReader::new();
    let n: i32 = input.next();
    let ve: Vec<i32> = input.next_vec();

    fn compute_function(compute: ComputeSet, val: i32) -> ComputeSet {
        let mut storage = compute.storage;
        let now = storage.get(&val).unwrap_or(&0);
        let result = compute.result + now;
        storage.insert(val, now + 1);
        return ComputeSet {
            storage: storage,
            result: result,
        };
    }

    let answer = ve
        .into_iter()
        .enumerate()
        .map(|(i, val)| val - i as i32)
        .fold(
            ComputeSet {
                storage: HashMap::new(),
                result: 0,
            },
            compute_function,
        )
        .result
        * 2;
    println!("{}", answer);
}
