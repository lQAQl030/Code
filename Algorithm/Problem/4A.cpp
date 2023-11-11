#include <bits/stdc++.h>
using namespace std;

bool all_catch(int &n, vector<int>& points, vector<pair<int, int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    for(const auto& interval : intervals){
        auto it = lower_bound(points.begin(), points.end(), interval.first);
        
        if(it != points.end() && *it <= interval.second){
            points.erase(it);
        }else{
            return false;
        }
    }

    return true;
}

int main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    int t, n;
    for(cin >> t ; t > 0 ; t--){
        cin >> n;
        int x;
        vector<int> points;
        for(int i = 0 ; i < n ; i++){
            cin >> x;
            points.push_back(x);
        }
        sort(points.begin(), points.end());

        pair<int,int> interval;
        vector<pair<int,int>> intervals;
        for(int i = 0 ; i < n ; i++){
            cin >> interval.first >> interval.second;
            intervals.push_back(interval);
        }

        cout << (all_catch(n, points, intervals) ? "Yes" : "No") << "\n";
    }
    
    return 0;
}