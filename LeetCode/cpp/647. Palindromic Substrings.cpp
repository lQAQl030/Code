class Solution {
public:
    int palin(string &s, int i, int j){
        int count = 0;
        while(i >= 0 && j < s.length() && s[i--] == s[j++]) count++;
        return count;
    }

    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0 ; i < s.length() ; i++){
            ans += palin(s, i, i);
            ans += palin(s, i, i+1);
        }
        return ans;
    }
};