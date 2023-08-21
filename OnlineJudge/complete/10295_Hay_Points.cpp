#include<bits/stdc++.h>
using namespace std;

int main(){

    int m , n = 0;
    while(cin >> m >> n && m && n){

        string line[m] = {};
        float money[m] = {};


        for(int i = 0 ; i < m ; i++){
            cin >> line[i] >> money[i];
        }

        string test = "";
        float sum = 0;
        while(n > 0){
            cin >> test;
            if(test == ".") {
                n--;
                cout << sum << endl;
                sum = 0;
                continue;
            }
            for(int i = 0 ; i < m ; i++){
                if(test == line[i]) sum += money[i];
            }
        }

    }

    return 0;
}