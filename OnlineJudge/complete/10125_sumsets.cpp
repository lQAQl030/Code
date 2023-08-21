#include <iostream>
#include<stdlib.h>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  
  int n = 0;
  while(cin >> n && n != 0){
    vector<int> array;
  int number = 0;
  int target = INT_MAX;
    for(int i = 0 ; i < n ; i++){
      cin >> number;
      array.push_back(number);
    }

    sort(array.begin() , array.end());

    for(int i = array.size()-1 ; i >= 0 ; i--){
      for(int j = 0 ; j < array.size() ; j++){
        for(int k = j+1 ; k < array.size() ; k++){
          for(int l = k+1 ; l < array.size() ; l++){
            if(array[j]+array[k]+ array[l] == array[i] && j != i && k != i && l != i){
              target = array[i];
              goto end;
            }
          }
        }
      }
    }

    end:
      if(target == INT_MAX){
        cout << "no solution" << endl;
      }else{
        cout << target << endl;
      }
  }

  return 0;
}
