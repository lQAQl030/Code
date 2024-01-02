class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        int rows = 0;
        for(int &i : nums){
            rows = max(rows, ++mp[i]);
        }
        vector<vector<int>> ans(rows);
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            for(int i = 0 ; i < it->second ; i++){
                ans[i].push_back(it->first);
            }
        }
        return ans;
    }
};