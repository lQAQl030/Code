class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n3 = nums.size() / 3;
        vector<vector<int>> ans(n3);

        for(int i = 0 ; i < n3 ; i++){
            ans[i].assign(nums.begin() + i*3, nums.begin() + i*3 + 3);
            if(ans[i][2] - ans[i][0] > k) return {};
        }
        return ans;
    }
};