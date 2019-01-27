#include <iostream>
using namespace std;

int main(void){
  int N, Q;
  int count {1};
  char judge;
  string alpha;

  cin >> N >> Q;

  for (int i=0; i<N; i++){
    alpha += 'A' + i;
  }

  while(count > 0){
    count = 0;
    for (int i=0; i<N-1; i++){
      cout << "? " << alpha[i] << " " << alpha[i+1] << endl;
                                                       cin >> judge;
      if(judge == '>'){
        count++;
        swap(alpha[i], alpha[i+1]);
      }
    }
  }

  cout << "! " << alpha << endl;
  return 0;
}
