class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> ans;
        int n = nums.size() / 3;
        for(int i : nums) m[i]++;
        for(auto it = m.begin() ; it != m.end() ; it++){
            if(it->second > n) ans.push_back(it->first);
        }
        return ans;
    }
};