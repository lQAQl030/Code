class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> vp(75, {0, '0'});
        for(char &c : s){
            int n = c - '0';
            vp[n].first++;
            vp[n].second = c;
        }
        sort(vp.begin(), vp.end(), greater<>());
        string ans;
        for(auto &p : vp){
            if(p.first != 0) ans.append(p.first, p.second);
        }
        return ans;
    }
};