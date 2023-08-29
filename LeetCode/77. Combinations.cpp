class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> vans;
        vector<int> ans;
        solve(1, n, k, ans, vans);
        return vans;
    }
private:
    void solve(int current, int n, int k, vector<int> &ans, vector<vector<int>> &vans){
        if(ans.size() == k){
            vans.push_back(ans);
            return;
        }

        for(int i = current ; i <= n ; i++){
            ans.push_back(i);
            solve(i+1, n, k, ans, vans);
            ans.pop_back();
        }
    }
};