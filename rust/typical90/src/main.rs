use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let v: Vec<&str> = input.trim().split(" ").collect();
    // println!("{},{}", v[0], v[1]);
    let N: usize = v[0].parse().unwrap();
    let L: u32 = v[1].parse().unwrap();

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    // println!("{}", input);
    let K: u32 = input.trim().parse().unwrap();

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let in_a: Vec<u32> = input
        .trim()
        .split(" ")
        .map(|x| x.parse().unwrap())
        .collect();

    let mut A: Vec<u32> = vec![0; N + 1];
    A[0] = in_a[0];
    // println!("{}", A[0]);
    for i in 1..N {
        A[i] = in_a[i] - in_a[i - 1];
        // println!("{}", A[i]);
    }
    A[N] = L - in_a[N - 1];
    // println!("{}", A[0]);

    let mut min = 0;
    let mut max = L;

    while min != max {
        let mid = (min + max + 1) / 2;

        let mut cnt = 0;
        let mut len = 0;
        for v in &A {
            if len + v >= mid {
                cnt += 1;
                len = 0;
            } else {
                len += v;
            }
        }
        if cnt < K + 1 {
            max = mid - 1;
        } else {
            min = mid;
        }
    }
    println!("{}", min);
}
