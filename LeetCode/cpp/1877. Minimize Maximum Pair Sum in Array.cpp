class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        int i = -1, j = nums.size();
        while(++i < --j) ans = max(nums[i] + nums[j], ans);
        return ans;
    }
};