class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int a = 0, b = 0;
        for(int i : nums) a ^= i;
        for(int i : nums) if(i & a & -a) b ^= i;
        return {static_cast<int>(b), static_cast<int>(a ^ b)};
    }
};