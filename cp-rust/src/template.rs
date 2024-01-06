/*
    Author: Manash Baul <mximpaid@gmail.com>
    Comment: The deeper you go, the more still you become.
*/

use std::cmp::{max, min};
use std::collections::{BTreeMap, BTreeSet, HashMap, HashSet, VecDeque};
use std::env;
use std::fs::File;
use std::io::{self, BufRead, BufReader, BufWriter, Write};

type I64 = i64;
const INF: i32 = 1e9 as i32;

struct InputReader {
    lines: std::io::Lines<BufReader<File>>,
}

impl InputReader {
    fn new() -> InputReader {
        const FILE_PATH: &str = "input.txt";
        let file = File::open(FILE_PATH).expect("Unable to open file");
        let reader = BufReader::new(file);
        InputReader {
            lines: reader.lines(),
        }
    }

    fn next<T: FromStr>(&mut self) -> T
    where
        <T as FromStr>::Err: std::fmt::Debug,
    {
        self.lines.next().unwrap().unwrap().trim().parse().unwrap()
    }

    fn next_vec<T: FromStr>(&mut self) -> Vec<T>
    where
        <T as FromStr>::Err: std::fmt::Debug,
    {
        self.lines
            .next()
            .unwrap()
            .unwrap()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    }
}

const input: InputReader = InputReader::new();

fn solve() {
    let n = input.next();
    println("This is the {}th Fibonacci number.", n);
}

fn main() {
    for _ in 0..t {
        solve();
    }
}
