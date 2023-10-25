#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    int n,m,k;
    int count = 0;
    cin >> n >> m >> k;
    ll a[n], b[m];

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    for(int i = 0 ; i < m ; i++){
        cin >> b[i];
    }

    ll ans = 0;
    int j[n] = {0};
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> compare;
    for(int i = 0 ; i < n ; i++){
        compare.push({a[i]*a[i] + a[i]*b[j[i]] + b[j[i]]*b[j[i]], i});
    }
    while (count < k){
        ans ^= compare.top().first;
        int id = compare.top().second;
        compare.pop();
        if(j[id]+1 < m) {
            j[id]++;
            compare.push({a[id]*a[id] + a[id]*b[j[id]] + b[j[id]]*b[j[id]], id});
        }
        count++;
    }
    cout << ans << endl;

    return 0;
}