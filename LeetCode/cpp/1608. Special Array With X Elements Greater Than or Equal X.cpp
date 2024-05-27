class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+1, 0);
        for(int i : nums){
            for(int a = 1 ; a < n+1 ; a++){
                if(i >= a) v[a]++;
            }
        }
        int j = n;
        while(j > 0){
            if(v[j] == j) return j;
            j--;
        }
        return -1;
    }
};