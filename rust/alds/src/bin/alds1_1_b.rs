use std::io;

fn main() {
    let mut input = String::new();
    let stdin = io::stdin();

    stdin.read_line(&mut input).unwrap();
    let vals: Vec<i32> = input
        .trim()
        .split(" ")
        .map(|x| x.parse().unwrap())
        .collect();
    let mut x = vals[0];
    let mut y = vals[1];

    while y > 0 {
        let tmp = y;
        y = x % y;
        x = tmp;
    }
    println!("{}", x);
}
