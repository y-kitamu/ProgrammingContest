macro_rules! input {
    ( $n:expr; $x:ty ) => {{
        let mut buffer = String::new();
        let stdin = std::io::stdin();
        stdin.read_line(&mut buffer).unwrap();
        let mut splits = buffer.trim().split(' ');
        (0..$n).map(|_| splits.next().unwrap().parse::<$x>().unwrap()).collect::<Vec<$x>>()
    }};

    ( $( $x:ty ), *) => {{
        let mut buffer = String::new();
        let stdin = std::io::stdin();
        stdin.read_line(&mut buffer).unwrap();
        let mut splits = buffer.trim().split(' ');
        ($(splits.next().unwrap().parse::<$x>().unwrap(),)*)
    }};
}

pub fn index_sort<T>(array: &[T]) -> Vec<usize>
where
    T: PartialOrd,
{
    let mut indices = (0..array.len()).collect::<Vec<usize>>();
    indices.sort_by(|lhs, rhs| array[*lhs].partial_cmp(&array[*rhs]).unwrap());
    indices
}

fn main() {
    let mods = 998244353;
    let (n, k): (usize, usize) = input!(usize, usize);

    let p: Vec<usize> = input!(n; usize);
    let q: Vec<usize> = input!(n; usize);

    let ps = index_sort(&p);
    let qs: Vec<usize> = ps.iter().map(|val| q[*val] - 1).collect();

    let mut dp = vec![vec![0; n + 1]; k + 1];
    dp[0][n] = 1;
    // current q index
    for i in 0..n {
        let mut next = vec![vec![0; n + 1]; k + 1];
        // current number of cands
        for j in 0..=k {
            // current max order
            for l in 0..=n {
                if qs[i] < l {
                    if j < k {
                        next[j + 1][l] = (next[j + 1][l] + dp[j][l]) % mods;
                    }
                    next[j][qs[i]] = (next[j][qs[i]] + dp[j][l]) % mods;
                } else {
                    next[j][l] = (next[j][l] + dp[j][l]) % mods;
                }
            }
        }
        // println!("{:?}", next);
        dp = next;
    }

    let ans = dp[k].iter().fold(0, |acc, val| (val + acc) % mods);
    println!("{}", ans);
}
