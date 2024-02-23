class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int prev = nums[0];
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != prev){
                count += i;
                prev = nums[i];
            }
        }
        return count;
    }
};