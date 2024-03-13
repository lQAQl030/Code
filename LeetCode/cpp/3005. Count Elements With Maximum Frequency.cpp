class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int max_freq = 0;
        for(int &i : nums){
            mp[i]++;
            if(mp[i] > max_freq) max_freq = mp[i];
        }

        int sum = 0;
        for(auto &[key, val] : mp){
            if(val == max_freq) sum += val;
        }

        return sum;
    }
};