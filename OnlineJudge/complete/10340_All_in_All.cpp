#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    while(cin >> s >> t){
        int m = 0;
        for(int i = 0 ; i < t.size() ; i++){
            if(t[i] == s[m]){
                m++;
            }
            if(m == s.size()){
                cout << "Yes" << endl;
                goto exit;
            }
        }
        cout << "No" << endl;
        exit:
            continue;
    }
}