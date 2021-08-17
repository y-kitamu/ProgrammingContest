use std::io::Read;

fn main() {
    let mut inputs = String::new();
    std::io::stdin().read_to_string(&mut inputs).ok();
    let mut itr = inputs.trim().split_whitespace();

    let h: usize = itr.next().unwrap().parse().unwrap();
    let w: usize = itr.next().unwrap().parse().unwrap();
    let grid: Vec<Vec<usize>> = (0..h)
        .map(|_| {
            (0..w)
                .map(|_| itr.next().unwrap().parse().unwrap())
                .collect()
        })
        .collect();

    let mut rows: Vec<usize> = vec![0; h];
    let mut cols: Vec<usize> = vec![0; w];
    for y in 0..h {
        for x in 0..w {
            rows[y] += grid[y][x];
            cols[x] += grid[y][x];
        }
    }

    for y in 0..h {
        println!(
            "{}",
            cols.iter()
                .zip(&grid[y])
                .map(|(x, val)| (x + rows[y] - val).to_string())
                .collect::<Vec<String>>()
                .join(" ")
        );
    }
}
