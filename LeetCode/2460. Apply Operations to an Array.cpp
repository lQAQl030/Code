class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans;

        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                count++;
                continue;
            }

            if(i + 1 < nums.size() && nums[i] == nums[i+1]){
                ans.push_back(nums[i++] * 2);
                count++;
                continue;
            }

            ans.push_back(nums[i]);
        }

        ans.resize(ans.size() + count);
        
        return ans;
    }
};