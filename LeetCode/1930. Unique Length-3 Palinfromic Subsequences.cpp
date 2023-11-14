class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans;
        vector<bool> used(26, false);
        int n = s.length();
        for(int i = 0 ; i < n-2 ; i++){
            if(used[s[i]-'a'] == true) continue;

            int j = n-1;
            while(s[i] != s[j]) j--;
            vector<bool> temp(26, false);
            for(int k = i+1 ; k < j ; k++){
                if(temp[s[k]-'a'] == false){
                    ans++;
                    temp[s[k]-'a'] = true;
                }
            }

            used[s[i]-'a'] = true;
        }
        return ans;
    }
};