class Solution {
public:
    int percentageLetter(string s, char letter) {
        float count = 0;
        for(char c : s) if(c == letter) count++;
        return floor(count*100 / s.size());
    }
};