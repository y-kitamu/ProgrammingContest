use std::io;

fn main() {
    let mut buffer = String::new();
    let stdin = io::stdin();
    stdin.read_line(&mut buffer).unwrap();

    let n: usize = buffer.trim().parse().unwrap();
    let act: Vec<Vec<usize>> = (0..n)
        .map(|_| {
            let mut buf = String::new();
            stdin.read_line(&mut buf).unwrap();
            buf.trim()
                .split(' ')
                .map(|val| val.parse().unwrap())
                .collect()
        })
        .collect();

    let mut cur: Vec<usize> = vec![0; 3];
    for i in 0..n {
        let mut next: Vec<usize> = vec![0; 3];
        for j in 0..3 {
            next[j] = std::cmp::max(cur[(j + 1) % 3], cur[(j + 2) % 3]) + act[i][j];
        }
        cur = next;
    }

    println!("{}", cur.iter().max().unwrap());
}
