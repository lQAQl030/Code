class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> dict(26, 0);
        for(char &c : chars) dict[c - 'a']++;

        int sum = 0;

        for(string &s : words){
            vector<int> now(26, 0);
            for(char &c : s) now[c - 'a']++;

            bool good = true;
            for(int i = 0 ; i < 26 ; i++){
                if(now[i] > dict[i]){
                    good = false;
                    break;
                }
            }

            if(good) sum += s.length();
        }

        return sum;
    }
};