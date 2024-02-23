class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> soldier;
        for(int i = 0 ; i < mat.size() ; i++){
            soldier.push({accumulate(mat[i].begin(), mat[i].end(), 1), i});
            if(soldier.size() > k) soldier.pop();
        }

        vector<int> ans;
        while(ans.size() != k){
            ans.push_back(soldier.top().second);
            soldier.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};