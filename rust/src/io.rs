#[macro_export]
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
