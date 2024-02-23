class Solution {
public:
    bool check(string &s){
        int start = 0;
        int end = s.length() - 1;
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for(string &s : words){
            if(check(s)) return s;
        }
        return "";
    }
};