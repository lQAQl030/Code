class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for(char &c : s) mp[c]++;

        string ans;
        for(char &c : order){
            ans.append(mp[c], c);
            mp.erase(c);
        }
        for(auto &[key, val] : mp){
            ans.append(val, key);
        }

        return ans;
    }
};