#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> n;
        vector<pair<int,int> > vc;       
        for(int j = 0 ; j < n ; j++){
            int a,b;
            cin >> a >> b;
            vc.push_back({a,b});
        }

        map<string,int> mp;
        for(int i = 0 ; i < n-1 ; i++){
            for(int j = i+1 ; j < n ; j++){
                int my = (vc[j].second - vc[i].second);
                int mx = (vc[j].first - vc[i].first);
                int gcd = __gcd(abs(mx),abs(my));
                my /= gcd; mx /= gcd;
                int c = -(my)*vc[i].first + mx*vc[i].second;
                string str;
                if(my > 0 && mx < 0 || my < 0 && mx < 0){
                    my *= -1; mx *= -1;
                }
                if(my == 0){
                    mx = 1; c = vc[i].second;
                }
                if(mx == 0){
                    my = 1; c = vc[i].first;
                }
                str = to_string(my) + to_string(mx) + to_string(c);
                mp[str]++;
            }
        }
        cout << mp.size() << endl;
    }
}