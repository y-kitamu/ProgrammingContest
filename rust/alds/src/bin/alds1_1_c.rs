use std::io;
use std::str::FromStr;

fn main() {
    let reader = Reader::new(io::stdin());
    let n: isize = reader.read_val().unwrap();

    let mut cnt = 0;
    for i in 0..n {
        let val: usize = reader.read_val().unwrap();
        let max = (val as f64).sqrt().ceil() as usize + 1;
        let mut flag = true;
        for i in 2..max {
            if val == i {
                break;
            }
            if val % i == 0 {
                flag = false;
                break;
            }
        }
        if flag {
            // println!("{}", val);
            cnt += 1;
        }
    }
    println!("{}", cnt);
}

struct Reader {
    stdin: io::Stdin,
}

impl Reader {
    fn new(stdin: io::Stdin) -> Reader {
        stdin.lock();
        Reader { stdin }
    }

    fn read_val<T: FromStr>(&self) -> Result<T, T::Err> {
        let mut input = String::new();
        self.stdin.read_line(&mut input).unwrap();
        input.trim().parse::<T>()
    }
}
