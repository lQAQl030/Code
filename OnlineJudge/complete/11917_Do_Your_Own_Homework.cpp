#include<bits/stdc++.h>
using namespace std;

int main(){

    // freopen("out.txt","w",stdout);
    int T;
    cin >> T;
    for(int i = 0 ; i < T ; i++){
        int n,t,d;
        string s;
        cin >> n;
        map<string,int> subject;
        for(int i = 0 ; i < n ; i++){
            cin >> s >> t;
            subject[s] = t;
        }

        cin >> d >> s;
        bool found = 0;
        for(map<string,int>::iterator it = subject.begin() ; it != subject.end() ; it++){
            if(it->first == s){
                if(it->second <= d) cout << "Case " << i+1 << ": Yesss" << endl;
                else if(it->second <= d+5) cout << "Case " << i+1 << ": Late" << endl;
                else cout << "Case " << i+1 << ": Do your own homework!" << endl;
                found = 1;
            }
        }
        if(!found) cout << "Case " << i+1 << ": Do your own homework!" << endl;
    }

    return 0;
}