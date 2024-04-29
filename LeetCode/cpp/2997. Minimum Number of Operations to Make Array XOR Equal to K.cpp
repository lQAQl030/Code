class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int i : nums) ans ^= i;
        ans ^= k;
        return __builtin_popcount(ans);
    }
};