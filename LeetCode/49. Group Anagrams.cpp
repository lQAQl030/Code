class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>, vector<string>> mp;
        
        for(string &s : strs){
            vector<int> ch(26, 0);
            for(char &c : s) ch[c - 'a']++;
            mp[ch].push_back(s);
        }

        for(auto &[key, value] : mp){
            ans.push_back(value);
        }

        return ans;
    }
};