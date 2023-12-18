class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int w = INT_MIN, x = INT_MIN;
        int y = INT_MAX, z = INT_MAX;
        for(int &i : nums){
            if(i > w){
                x = w;
                w = i;
            }else if(i > x){
                x = i;
            }
            if(i < y){
                z = y;
                y = i;
            }else if(i < z){
                z = i;
            }
        }

        return w*x - y*z;
    }
};