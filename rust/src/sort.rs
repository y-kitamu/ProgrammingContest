/// Sort index array by value of `array`. (ascending order)
///
/// # Examples
/// ```
/// use yklib::sort::index_sort;
///
/// let array: Vec<usize> = vec![2, 1, 5, 4, 3];
/// let sorted_index = index_sort(&array);
/// assert_eq!(sorted_index[0], 1);
/// assert_eq!(sorted_index[1], 0);
/// assert_eq!(sorted_index[2], 4);
/// assert_eq!(sorted_index[3], 3);
/// assert_eq!(sorted_index[4], 2);
/// ```
pub fn index_sort<T>(array: &[T]) -> Vec<usize>
where
    T: PartialOrd,
{
    let mut indices = (0..array.len()).collect::<Vec<usize>>();
    indices.sort_by(|lhs, rhs| array[*lhs].partial_cmp(&array[*rhs]).unwrap());
    indices
}
