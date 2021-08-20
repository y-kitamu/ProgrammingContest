use std::io;

fn main() {
    const MOD: isize = 1e9 as isize + 7;

    let stdin = io::stdin();
    let mut buffer = String::new();
    stdin.read_line(&mut buffer).unwrap();
    let n: isize = buffer.trim().parse().unwrap();

    let ans = mod_pow(10, n, MOD) - 2 * mod_pow(9, n, MOD) + mod_pow(8, n, MOD);
    println!("{}", (ans % MOD + MOD) % MOD)
}

fn mod_pow(n: isize, mut r: isize, m: isize) -> isize {
    let mut ans = 1;
    let mut pow = n;
    while r > 0 {
        if (r & 1) == 1 {
            ans = (ans * pow) % m;
        }
        pow = (pow * pow) % m;
        r >>= 1;
    }
    ans
}
