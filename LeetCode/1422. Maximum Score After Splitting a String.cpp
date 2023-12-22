class Solution {
public:
    int maxScore(string s) {
        int right = 0;
        for(char &c : s) if(c == '1') right++;

        int left = 0, sum = 0;
        for(int i = 0 ; i < s.size() - 1 ; i++){
            if(s[i] == '1') right--;
            else left++;
            sum = (sum < left + right) ? left + right : sum;
        }

        return sum;
    }
};