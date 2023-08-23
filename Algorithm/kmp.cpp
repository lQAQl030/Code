#include<bits/stdc++.h>
using namespace std;

int* NEXT(string p){
    int *next = new int[p.length()];
    next[0] = -1;
    int j = 0;
    int k = -1;

    while(j < p.length()-1){
        if(k == -1 || p[j] == p[k]){
            if(p[++j] == p[++k]){
                next[j] = next[k]+1;
            }else{
                next[j] = k;
            }
        }else{
            k = next[k];
        }
    }
    return next;
}

int KMP(string s, string p){

    int i = 0;
    int j = 0;
    int *next = NEXT(p);
    while(i < s.length() && j < p.length()){
        if(j == -1 || s[i] == p[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j == p.length()){
        return i - j;
    }else{
        return -1;
    }
}

int main(){

    freopen("out.txt","w",stdout);
    string s,p;
    while(cin >> s >> p){
        cout << "i = " << KMP(s,p) << endl;
        int *arr = NEXT(p);
        for(int i = 0 ; i < p.length() ; i++){
            cout << arr[i];
        }
        cout << endl;
    }

    return 0;
}