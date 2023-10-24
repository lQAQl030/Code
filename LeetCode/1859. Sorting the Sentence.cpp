class Solution {
public:
    string sortSentence(string s) {
        string ans;
        vector<string> v(10,"");
        for(char c : s){
            if('1' <= c && c <= '9'){
                v[c - '0'] = v[0] + " ";
                v[0].clear();
            }else if(c == ' '){
                continue;
            }else{
                v[0] += c;
            }
        }
        for(string str : v){
            ans += str;
        }
        ans.pop_back();
        return ans;
    }
};