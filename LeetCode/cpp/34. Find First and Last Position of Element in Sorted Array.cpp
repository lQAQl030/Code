class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        vector<int> v(2, INT_MAX);
        while(i <= j){
            if(nums[i] == target) v[0] = i;
            if(nums[j] == target) v[1] = j;
            if(v[0] != INT_MAX && v[1] != INT_MAX) return v;
            if(v[0] == INT_MAX) i++;
            if(v[1] == INT_MAX) j--;
        }
        return {-1, -1};
    }
};