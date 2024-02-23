class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<>());
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int i = 0;
        while(i < nums.size() && sum - nums[i] <= nums[i]){
            sum -= nums[i++];
        }
        return (sum) ? sum : -1;
    }
};