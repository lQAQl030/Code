class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        int count[101] = {0};
        for(int i = 0 ; i < nums.size() ; i++)
        {
            ans += count[nums[i]];
            count[nums[i]]++;
        }
        return ans;
    }
};