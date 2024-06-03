class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        while(i < s.size()){
            if(i < s.size() && s[i] == t[j]){
                j++;
                if(j >= t.size()) break;
            }
            i++;
        }
        return t.size() - j;
    }
};