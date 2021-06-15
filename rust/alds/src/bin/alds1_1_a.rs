use std::io;

fn main() {
    let mut input = String::new();
    let stdin = io::stdin();

    stdin.read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();

    let mut input = String::new();
    stdin.read_line(&mut input).unwrap();
    let mut a: Vec<u32> = input
        .trim()
        .split(" ")
        .map(|x| x.parse().unwrap())
        .collect();
    insertion_sort(&mut a, n);
}

fn insertion_sort(a: &mut Vec<u32>, n: usize) {
    let out: Vec<String> = a.iter().map(|x| format!("{}", x)).collect();
    println!("{}", out.join(" "));
    for i in 1..n {
        let v = a[i];
        let mut j: usize = i - 1;
        while a[j] > v {
            a[j + 1] = a[j];
            if j == 0 {
                break;
            }
            j -= 1;
        }
        if j > 0 || a[j] < v {
            a[j + 1] = v;
        } else {
            a[j] = v;
        }
        let out: Vec<String> = a.iter().map(|x| format!("{}", x)).collect();
        println!("{}", out.join(" "));
    }
}
