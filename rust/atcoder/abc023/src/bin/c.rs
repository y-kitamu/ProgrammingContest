use std::io::{self, Stdin};

fn main() {
    let stdin = io::stdin();
    let mut buffer = String::new();

    stdin.read_line(&mut buffer).unwrap();
    buffer.pop();
    let rck: Vec<usize> = buffer.split(' ').map(|s| s.parse().unwrap()).collect();
    let (r, c, k) = (rck[0], rck[1], rck[2]);

    let mut buffer = String::new();
    stdin.read_line(&mut buffer).unwrap();
    buffer.pop().unwrap();
    let n: usize = buffer.parse().unwrap();

    let mut cntr = vec![0; r];
    let mut cntc = vec![0; c];

    let rcs: Vec<Vec<usize>> = (0..n)
        .map(|_| {
            buffer.clear();
            stdin.read_line(&mut buffer).unwrap();
            buffer.pop().unwrap();
            let mut rc: Vec<usize> = buffer.split(' ').map(|s| s.parse().unwrap()).collect();
            rc[0] -= 1;
            rc[1] -= 1;
            cntr[rc[0]] += 1;
            cntc[rc[1]] += 1;
            rc
        })
        .collect();

    let mut nr = vec![0; k + 1];
    let mut nc = vec![0; k + 1];

    for i in 0..r {
        if cntr[i] <= k {
            nr[cntr[i]] += 1;
        }
    }
    for i in 0..c {
        if cntc[i] <= k {
            nc[cntc[i]] += 1;
        }
    }

    let mut sum: usize = 0;
    for i in 0..k + 1 {
        sum += nr[i] * nc[k - i];
    }

    for i in 0..n {
        let val = cntr[rcs[i][0]] + cntc[rcs[i][1]];
        if val == k {
            sum -= 1;
        }
        if val == k + 1 {
            sum += 1;
        }
    }
    println!("{}", sum);
}
