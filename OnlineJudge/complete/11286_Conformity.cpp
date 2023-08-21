#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    string arr[5] = {};
    string str = "";
    while(cin >> n && n){
        string strarr[n] = {};
        int pops = 0;
        map<string,int> combinition;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < 5 ; j++){
                cin >> arr[j];
            }
            sort(arr,arr+5);
            for(int j = 0 ; j < 5 ; j++){
                str = str + arr[j];
            }
            combinition[str]++;
            str = "";
        }
        int count = 0;
        for(map<string,int>::iterator it = combinition.begin(); it != combinition.end() ; it++){
            
            if(it->second > pops){
                pops = it->second;
                count = it->second;
            }else if(it->second == pops){
                count = count + it->second;
            }
        }
        cout << count << endl;
    }

}