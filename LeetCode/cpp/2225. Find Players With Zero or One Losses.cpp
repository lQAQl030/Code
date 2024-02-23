class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> mp;
        for(vector<int> &v : matches){
            mp[v[0]] += 0;
            mp[v[1]]++;
        }

        vector<vector<int>> lost(2);
        for(auto &[a,b] : mp){
            if(b == 0) lost[0].push_back(a);
            else if(b == 1) lost[1].push_back(a);
        }

        sort(lost[0].begin(), lost[0].end());
        sort(lost[1].begin(), lost[1].end());
        return lost;
    }
};