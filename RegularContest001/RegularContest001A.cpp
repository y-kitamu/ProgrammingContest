#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main(void){
  int N;
  array<int, 4> count {0};
  string ans;
  
  cin >> N;
  cin >> ans;

  for(int j=1; j<=4; j++){
    string correct_answer = to_string(j);
    for(int i=0; i<N; i++){
      if(ans[i] == correct_answer[0]){
        count[j-1]++;
      }
    }
  }
  
  int min = *min_element(count.begin(), count.end());
  int max = *max_element(count.begin(), count.end());

  cout << max << " " << min << endl;

  return 0;
}
