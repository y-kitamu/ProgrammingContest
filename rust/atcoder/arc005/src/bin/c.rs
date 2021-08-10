use std::io::{self, Read};
use std::{collections::VecDeque, str::FromStr};

fn main() {
    let mut buffer = String::new();
    let mut stdin = io::stdin();
    stdin.read_line(&mut buffer).unwrap();

    buffer.pop();
    let hw: Vec<usize> = buffer.split(' ').map(|s| s.parse().unwrap()).collect();

    let grid: Vec<Vec<char>> = (0..hw[0])
        .map(|_| {
            let mut buffer = String::new();
            stdin.read_line(&mut buffer);
            let row: Vec<char> = buffer.chars().collect();
            row
        })
        .collect();

    let mut sx: usize = 0;
    let mut sy: usize = 0;
    let mut gx: usize = 0;
    let mut gy: usize = 0;
    for y in 0..hw[0] {
        for x in 0..hw[1] {
            if grid[y][x] == 's' {
                sx = x;
                sy = y;
            }
            if grid[y][x] == 'g' {
                gx = x;
                gy = y;
            }
        }
    }

    let mut cost: Vec<Vec<usize>> = (0..hw[0])
        .map(|_| {
            let vec: Vec<usize> = (0..hw[1]).map(|_| 1e9 as usize).collect();
            vec
        })
        .collect();

    let mut que: VecDeque<(usize, usize, usize)> = VecDeque::new();
    que.push_back((sx, sy, 0));

    while !que.is_empty() {
        let (x, y, c) = que.pop_front().unwrap();
        if c < cost[y][x] {
            cost[y][x] = c;
            if x > 0 {
                push(x - 1, y, c, &grid, &cost, &mut que);
            }
            if y > 0 {
                push(x, y - 1, c, &grid, &cost, &mut que);
            }
            if x < hw[1] - 1 {
                push(x + 1, y, c, &grid, &cost, &mut que);
            }
            if y < hw[0] - 1 {
                push(x, y + 1, c, &grid, &cost, &mut que);
            }
        }
    }

    if cost[gy][gx] <= 2 {
        println!("YES");
    } else {
        println!("NO");
    }
}

fn push(
    x: usize,
    y: usize,
    c: usize,
    grid: &Vec<Vec<char>>,
    cost: &Vec<Vec<usize>>,
    que: &mut VecDeque<(usize, usize, usize)>,
) {
    if grid[y][x] == '#' {
        if c + 1 < cost[y][x] {
            que.push_back((x, y, c + 1));
        }
    } else {
        if c < cost[y][x] {
            que.push_front((x, y, c));
        }
    }
}
