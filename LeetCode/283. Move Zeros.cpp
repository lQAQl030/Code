class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        stable_partition(nums.rbegin(), nums.rend(), logical_not<int>());
    }
};