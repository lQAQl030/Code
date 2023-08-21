#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    bool act = 0;
    while(cin >> n){
        char c;
        string str = "" , temp = "";
        map<string,int> text;
        while(getline(cin , temp)){
            if(temp == "EndOfText") break;
            if(temp == "") continue;
            if(str.size() != 0){
                    text[str]++;
                    str = "";
            }
            for(int i = 0 ; i < temp.size() ; i++){
                c = temp[i];
                if(isalpha(c)){
                    if('A' <= c && c <= 'Z') c += 32;
                    str += c;
                }else if(str.size() != 0){
                    text[str]++;
                    str = "";
                }
            }
        }

        if(act) cout << endl;
        bool ok = 0;
        for(map<string,int>::iterator it = text.begin() ; it != text.end() ; it++){
            if(it -> second == n){
                cout << it -> first << endl;
                ok = 1;
            }
        }
        if(!ok) cout << "There is no such word." << endl;
        act = 1;
        
    }

    return 0;
}