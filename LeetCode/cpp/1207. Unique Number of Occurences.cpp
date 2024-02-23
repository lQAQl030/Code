class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int &i : arr) mp[i]++;

        unordered_set<int> s;
        for(auto &[key, value] : mp){
            if(!s.insert(value).second) return false;
        }
        
        return true;
    }
};