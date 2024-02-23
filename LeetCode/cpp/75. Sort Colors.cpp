class Solution {
public:
    void find(vector<int>& nums, int i, int j, bool &check){
        if(check) return;
        for(; i < j ; i++){
            if(nums[i] == 2){
                swap(nums[i], nums[j]);
                return;
            }
        }
        check = true;
        return;
    }

    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size()-1, last = 0;
        while(i < j){
            if(nums[i] == 0){
                i++;
            }else if(nums[i] == 2){
                swap(nums[i], nums[j]);
                while(nums[j] == 2 && j > i){
                    j--;
                    swap(nums[i], nums[j]);
                    last = j;
                }
            }else{
                i++;
            }
        }
        i = 0;
        while(i < j){
            if(nums[i] == 0 || nums[j] == 2){
                if(nums[j] == 2){
                    j--;
                    continue;
                }
                i++;
            }else{
                swap(nums[i], nums[j]);
                while(nums[j] == 1 && j > i){
                    j--;
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
};