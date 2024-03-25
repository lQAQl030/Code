class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> count(nums.size()+1);
        for(int i : nums) count[i]++;
        vector<int> ans;
        for(int i = 1 ; i <= nums.size() ; i++) if(count[i] == 2) ans.push_back(i);
        return ans; 
    }
};