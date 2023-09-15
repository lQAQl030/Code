class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int limit = nums.size() / 2;
        for(int i = 0 ; i < nums.size() ; i++){
            m[nums[i]]++;
            if(m[nums[i]] > limit) return nums[i];
        }
        return limit;
    }
};