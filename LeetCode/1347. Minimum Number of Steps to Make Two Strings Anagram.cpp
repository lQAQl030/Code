class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> dic(26, 0);
        for(char &c : s) dic[c-'a']++;
        for(char &c : t) dic[c-'a']--;

        int steps = 0;
        for(int &i : dic) steps += (i > 0) ? i : 0;
        return steps;
    }
};