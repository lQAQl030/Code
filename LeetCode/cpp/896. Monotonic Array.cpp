class Solution {
public:
    // Fast I/O
    Solution(){
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }

    bool isMonotonic(vector<int>& nums) {
        bool increase = true;
        bool decrease = true;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i-1] < nums[i]) decrease = false;
            else if(nums[i-1] > nums[i]) increase = false;
            if(!increase && !decrease) return false;
        }
        return true;
    }
};