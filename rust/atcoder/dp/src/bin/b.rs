use std::cmp::min;
use std::io;

fn main() {
    let mut buffer = String::new();
    let stdin = io::stdin();
    stdin.read_line(&mut buffer).unwrap();

    let nk: Vec<usize> = buffer
        .trim()
        .split(' ')
        .map(|val| val.parse().unwrap())
        .collect();
    let n = nk[0];
    let k = nk[1];

    buffer.clear();
    stdin.read_line(&mut buffer).unwrap();
    let h: Vec<isize> = buffer
        .trim()
        .split(' ')
        .map(|val| val.parse().unwrap())
        .collect();

    let mut cost: Vec<usize> = vec![2e9 as usize; n];
    cost[0] = 0;
    for i in 0..n {
        for j in (i + 1)..min(n, i + k + 1) {
            cost[j] = min(cost[j], cost[i] + (h[j] - h[i]).abs() as usize);
        }
    }
    println!("{}", cost[n - 1]);
}
