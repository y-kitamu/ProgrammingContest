#include <iostream>
#include <complex>
using namespace std;

int count_buttom_pushed(const int level, const int boundary, int& diff){
  int count;
  
  count = diff / level;
  diff = diff - count * level;
  if (diff % level >= boundary){
    count++;
    diff = abs(diff - level);
  }

  return count;
}

int main(void){
  int A, B;
  cin >> A >> B;

  int diff = abs(A - B);
  int p10, p5, p1;

  int count {0};
  count += count_buttom_pushed(10, 8, diff);
  count += count_buttom_pushed(5, 4, diff);
  count += count_buttom_pushed(1, 1, diff);

  cout << count << endl;

  return 0;
}
