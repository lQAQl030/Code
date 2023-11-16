#include <bits/stdc++.h>
using namespace std;

void build_sequence(vector<vector<int>>& cuts, int left, int right){
    if(right - left == 1) return;
    cout << cuts[left][right] << " ";
    build_sequence(cuts, left, cuts[left][right]);
    build_sequence(cuts, cuts[left][right], right);
}

int main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);

    int n;
    cin >> n;
    n++;
    vector<int> points(n);
    points[0] = 0;
    for(int i = 1 ; i < n ; i++) cin >> points[i];
    
    vector<vector<int>> dp(n,vector<int>(n));
    vector<vector<int>> cuts(n,vector<int>(n));
    for(int len = 2 ; len < n ; len++){
        for(int left = 0 ; left + len < n ; left++){
            int right = left + len;
            dp[left][right] = INT_MAX;
            for(int i = left + 1 ; i < right ; i++){
                int cost = dp[left][i] + dp[i][right] + abs((points[right] - points[i]) - (points[i] - points[left]));
                if(cost < dp[left][right]){
                    dp[left][right] = cost;
                    cuts[left][right] = i;
                }
            }
        }
    }


    cout << dp[0][n-1] << endl;
    build_sequence(cuts, 0, n-1);
    
    // cout << endl;
    // cout << "------------DP------------" << endl;
    // for(auto v : dp){
    //     for(int i : v) cout << i << " ";
    //     cout << endl;
    // }
    // cout << "------------Cuts------------" << endl;
    // for(auto v : cuts){
    //     for(int i : v) cout << i << " ";
    //     cout << endl;
    // }

    return 0;
}