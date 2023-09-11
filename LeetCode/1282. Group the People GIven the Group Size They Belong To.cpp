class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans(groupSizes.size());
        vector<vector<int>> total;
        for(int i = 0 ; i < groupSizes.size() ; i++){
            ans[groupSizes[i]-1].push_back(i);
            if(ans[groupSizes[i]-1].size() == groupSizes[i]){
                total.push_back(ans[groupSizes[i]-1]);
                ans[groupSizes[i]-1].clear();
            }
        }
        return total;
    }
};