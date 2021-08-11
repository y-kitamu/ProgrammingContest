use std::{
    cmp::{max, min},
    collections::VecDeque,
    io,
};

fn main() {
    let (h, w) = read_pair();
    let (cy, cx) = read_pair();
    let (dy, dx) = read_pair();
    let (cy, cx) = (cy - 1, cx - 1);
    let (dy, dx) = (dy - 1, dx - 1);

    let stdin = io::stdin();
    let grid: Vec<Vec<char>> = (0..h)
        .map(|_| {
            let mut buffer = String::new();
            stdin.read_line(&mut buffer).unwrap();
            buffer.trim().chars().collect()
        })
        .collect();
    let mut score: Vec<Vec<isize>> = vec![vec![-1; w]; h];

    let mut que: VecDeque<(usize, usize)> = VecDeque::new();

    score[cy][cx] = 0;
    que.push_back((cy, cx));
    while let Some((y, x)) = que.pop_front() {
        if y == dy && x == dx {
            break;
        }

        let cur = score[y][x];
        if y > 1 && grid[y - 1][x] == '.' && (score[y - 1][x] == -1 || cur < score[y - 1][x]) {
            score[y - 1][x] = cur;
            que.push_front((y - 1, x));
        }
        if x > 1 && grid[y][x - 1] == '.' && (score[y][x - 1] == -1 || cur < score[y][x - 1]) {
            score[y][x - 1] = cur;
            que.push_front((y, x - 1));
        }
        if y < h - 1 && grid[y + 1][x] == '.' && (score[y + 1][x] == -1 || cur < score[y + 1][x]) {
            score[y + 1][x] = cur;
            que.push_front((y + 1, x));
        }
        if x < w - 1 && grid[y][x + 1] == '.' && (score[y][x + 1] == -1 || cur < score[y][x + 1]) {
            score[y][x + 1] = cur;
            que.push_front((y, x + 1));
        }

        for dy in max(0, y as isize - 2) as usize..=min(h - 1, y + 2) {
            for dx in max(0, x as isize - 2) as usize..=min(w - 1, x + 2) {
                if grid[dy][dx] == '.' && (score[dy][dx] == -1 || cur + 1 < score[dy][dx]) {
                    score[dy][dx] = cur + 1;
                    que.push_back((dy, dx));
                }
            }
        }
    }
    println!("{}", score[dy][dx])
}

fn read_pair() -> (usize, usize) {
    let mut buffer = String::new();
    let stdin = io::stdin();
    stdin.read_line(&mut buffer).unwrap();
    let pair: Vec<usize> = buffer
        .trim()
        .split(' ')
        .map(|s| s.parse().unwrap())
        .collect();
    (pair[0], pair[1])
}
