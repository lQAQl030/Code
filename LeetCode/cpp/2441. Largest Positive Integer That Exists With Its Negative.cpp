class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1;
        while(i < j){
            int neg = nums[j] * -1;
            if(nums[i] == neg) return abs(neg);
            else if(nums[i] < neg) i++;
            else j--;
        }
        
        return -1;
    }
};