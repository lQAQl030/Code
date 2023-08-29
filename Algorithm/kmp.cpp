#include<bits/stdc++.h>
using namespace std;

int* NEXT(string p){
    int *next = new int[p.length()];
    next[0] = 0;
    int j = 1;
    int k = 0;

    while(j < p.length()){
        if(p[j] == p[k]){
            k++;
            next[j] = k;
            j++;
        }else if(k != 0){
            k = next[k-1];
        }else{
            j++;
            next[j] = k;
        }
    }
    return next;
}

int KMP(string s, string p){

    int i = 0;
    int j = 0;
    int *next = NEXT(p);
    while(i < s.length() && j < p.length()){
        if(s[i] == p[j]){
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