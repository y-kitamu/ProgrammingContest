fn main() {
    let mut buffer = String::new();
    let stdin = std::io::stdin();
    stdin.read_line(&mut buffer).unwrap();
    let nw: Vec<usize> = buffer
        .trim()
        .split(' ')
        .map(|val| val.parse().unwrap())
        .collect();

    let mut w: Vec<usize> = vec![0; nw[0]];
    let mut v: Vec<usize> = vec![0; nw[0]];
    (0..nw[0]).for_each(|idx| {
        let mut buffer = String::new();
        let stdin = std::io::stdin();
        stdin.read_line(&mut buffer).unwrap();
        let mut vals = buffer.trim().split(' ').map(|val| val.parse().unwrap());
        w[idx] = vals.next().unwrap();
        v[idx] = vals.next().unwrap();
    });

    let mut vals = vec![0; nw[1] + 1];
    let mut ans = 0;
    for i in 0..nw[0] {
        for j in (w[i]..=nw[1]).rev() {
            vals[j] = usize::max(vals[j - w[i]] + v[i], vals[j]);
            ans = usize::max(ans, vals[j]);
        }
    }
    println!("{}", ans);
}
