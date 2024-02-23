class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<pair<int,int>> pos(26,{-1,-1});
        for(int i = 0 ; i < s.size() ; i++){
            int c = s[i] - 'a';
            if(pos[c].first == -1){
                pos[c].first = i;
            }else{
                pos[c].second = i;
            }
        }
        int sub = -1;
        for(int i = 0 ; i < 26 ; i++){
            if(pos[i].second == -1) continue;
            if(pos[i].first == pos[i].second && s[pos[i].first] == s[pos[i].second]) sub = max(sub, 0);
            else sub = max(sub, pos[i].second - pos[i].first - 1);
        }
        return sub;
    }
};