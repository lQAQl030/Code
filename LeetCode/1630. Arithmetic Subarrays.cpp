class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        vector<int> temp;
        for(int i = 0 ; i < l.size() ; i++){
            temp.assign(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(temp.begin(), temp.end());

            bool isArith = true;
            int diff = temp[1] - temp[0];
            for(int j = 2 ; j < temp.size() ; j++){
                if(temp[j] - temp[j-1] != diff){
                    isArith = false;
                    break;
                }
            }

            ans.push_back(isArith);
        }
        return ans;
    }
};