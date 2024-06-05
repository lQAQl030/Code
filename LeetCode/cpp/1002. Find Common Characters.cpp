class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> prev(26, 0);
        for(char c : words[0]) prev[c-'a']++;

        for(int s = 1 ; s < words.size() ; s++){
            vector<int> now(26, 0);
            for(char c : words[s]){
                now[c-'a']++;
            }
            for(int i = 0 ; i < 26 ; i++){
                prev[i] = min(prev[i], now[i]);
            }
        }
        
        vector<string> ans;
        for(int i = 0 ; i < 26 ; i++){
            char c = 'a' + i;
            while(prev[i]-- > 0){
                ans.push_back(string(1, c));
            }
        }
        return ans;
    }
};