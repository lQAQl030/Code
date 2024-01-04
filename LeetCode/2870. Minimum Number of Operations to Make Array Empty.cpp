class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int &i : nums) mp[i]++;

        int count = 0;
        for(auto &a : mp){
            if(a.second == 1) return -1;
            count += a.second / 3;
            if(a.second % 3) count++;
        }
        return count;
    }
};