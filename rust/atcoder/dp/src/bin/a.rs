use std::{cmp::min, io};

fn main() {
    let mut buffer = String::new();
    let stdin = io::stdin();
    stdin.read_line(&mut buffer).unwrap();
    let n: usize = buffer.trim().parse().unwrap();

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
        if i + 1 < n {
            cost[i + 1] = min(cost[i] + (h[i + 1] - h[i]).abs() as usize, cost[i + 1]);
        }
        if i + 2 < n {
            cost[i + 2] = min(cost[i] + (h[i + 2] - h[i]).abs() as usize, cost[i + 2]);
        }
    }
    println!("{}", cost[n - 1]);
}
