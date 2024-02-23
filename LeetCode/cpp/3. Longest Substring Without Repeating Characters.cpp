class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> char_id(128, -1);
        int left = 0, len_max = 0;
        for(int right = 0 ; right < s.size() ; right++){
            if(char_id[s[right]] >= left){
                left = char_id[s[right]] + 1;
            }
            char_id[s[right]] = right;
            len_max = max(len_max, right - left + 1);
        }
        return len_max;
    }
};