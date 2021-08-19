use std::io;

fn main() {
    let mut buffer = String::new();
    let stdin = io::stdin();

    stdin.read_line(&mut buffer).unwrap();
    let mut itr = buffer.trim().split(' ');
    let l: u64 = itr.next().unwrap().parse().unwrap();
    let r: u64 = itr.next().unwrap().parse().unwrap();

    let mut exclude: Vec<usize> = vec![0; r as usize + 1];
    let mut j = 2;
    while j * j <= r {
        for num in ((j * j)..=r).step_by((j * j) as usize) {
            exclude[num as usize] = 1;
        }
        j += 1;
    }

    let mut num_primes: Vec<isize> = vec![0; r as usize + 1];

    for i in 2..=r {
        if num_primes[i as usize] == 0 {
            for j in (i..=r).step_by(i as usize) {
                num_primes[j as usize] += 1;
            }
        }
    }

    let mut sum: u64 = 0;
    for i in 2..=r {
        if exclude[i as usize] == 1 {
            continue;
        }
        let num = r / i - (l - 1) / i;
        if num <= 1 {
            continue;
        }
        let num = num * (num - 1) / 2;
        if num_primes[i as usize] % 2 == 1 {
            sum += num;
        } else {
            sum -= num;
        }
    }

    for i in std::cmp::max(l, 2)..=r {
        sum -= r / i - 1;
    }

    println!("{}", sum * 2);
}
