class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> ans(n);
        int left = 0, right = n - 1;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(abs(nums[right] > abs(nums[left]))) ans[i] = nums[right] * nums[right--];
            else ans[i] = nums[left] * nums[left++];
        }
        return ans;
    }
};