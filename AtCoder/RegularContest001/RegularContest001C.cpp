#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int NSIZE {8};

int judgement(vector<int> ans_col, vector<int> q_raw){
  for(int i=0; i<NSIZE-1; i++){
    for(int j=i+1; j<NSIZE; j++){
      if(abs(ans_col[i] - ans_col[j]) == abs(q_raw[i] - q_raw[j]))
        return 0;
    }
  }
  return 1;
}
  
void output(vector<int> ans_col, vector<int> q_raw){
  for(int i=0; i<NSIZE; i++){
    int raw_index = distance(q_raw.begin(),
                             find(q_raw.begin(), q_raw.end(), i));
    for(int j=0; j<NSIZE; j++){
      int col_index = distance(ans_col.begin(),
                               find(ans_col.begin(), ans_col.end(), j));
      if(raw_index == col_index)
        cout << 'Q';
      else
        cout << '.';
    }
    cout << endl;
  }
  return; 
}
  
int depth_first_search(vector<int> e_col, vector<int> a_col,
                       const vector<int> q_raw){
  int judge;
  if (e_col.size() == 1){
    a_col.push_back(e_col[0]);
    judge = judgement(a_col, q_raw);
    if(judge == 1)
      output(a_col, q_raw);
    return judge;
  }
  for(auto itr=e_col.begin(); itr<e_col.end(); itr++){
    vector<int> new_e_col, new_a_col;
    copy(e_col.begin(), e_col.end(), back_inserter(new_e_col));
    copy(a_col.begin(), a_col.end(), back_inserter(new_a_col));
    int dist = distance(new_e_col.begin(),
                        find(new_e_col.begin(), new_e_col.end(), *itr));
    new_e_col.erase(new_e_col.begin() + dist);
    new_a_col.push_back(*itr);
    judge = depth_first_search(new_e_col, new_a_col, q_raw);
    if(judge == 1)
      break;
  }
  return judge;
}
  
int main(void){
  vector<int> q_raw, q_col;
  vector<int> empty_raw, empty_col;
  char input;

  // input
  for(int i=0; i<NSIZE; i++){
    for(int j=0; j<NSIZE; j++){
      cin >> input;
      if (input == 'Q'){
        q_raw.push_back(i);
        q_col.push_back(j);
      }
    }
  }
  
  // check duplication
  for(auto itr1=q_raw.begin(); itr1<q_raw.end()-1; itr1++){
    for(auto itr2=itr1+1; itr2<q_raw.end(); itr2++){
      if(*itr1 == *itr2){
        cout << "No Answer";
        return 0;
      }
    }
  }
  for(auto itr1=q_col.begin(); itr1<q_col.end()-1; itr1++){
    for(auto itr2=itr1+1; itr2<q_col.end(); itr2++){
      if(*itr1 == *itr2){
        cout << "No Answer";
        return 0;
      }
    }
  }

  size_t maxdepth = NSIZE - q_raw.size();
  
  for(int i=0; i<NSIZE; i++){
    if(find(q_raw.begin(), q_raw.end(), i) == q_raw.end())
      q_raw.push_back(i);
    if(find(q_col.begin(), q_col.end(), i) == q_col.end())
      empty_col.push_back(i);
  }

  // create answer and check condition
  int result = depth_first_search(empty_col, q_col, q_raw);
  if (result == 0)
    cout << "No Answer" << endl;
  
  return 0;
}
