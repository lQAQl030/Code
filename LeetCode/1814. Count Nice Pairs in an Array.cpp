class Solution {
public:
    #define mod 1000000007
    #define lli long long int

    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                mp[0]++;
                continue;
            }
            int r = 0;
            int n = nums[i];
            while(n > 0){
                r *= 10;
                r += n % 10;
                n /= 10;
            }
            mp[nums[i] - r]++;
        }

        lli ans = 0;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            ans += ((lli)it->second * (it->second - 1)) / 2;
            ans %= mod;
        }

        return (int)ans;
    }
};
// calculate the diff of nums[i] and it reverse
// count the same diff occurance by map
// use c(n,2) to calculate the answer