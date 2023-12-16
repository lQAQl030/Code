class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int letter[26] = {0};
        for(int i = 0 ; i < s.size() ; i++){
            letter[s[i] - 'a']++;
            letter[t[i] - 'a']--;
        }
        for(int &i : letter){
            if(i != 0) return false;
        }
        return true;
    }
};