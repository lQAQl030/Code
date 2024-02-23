class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[2][1001] = {};
        int n = text1.size(), m = text2.size();

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                dp[!(i % 2)][j+1] = (text1[i] == text2[j]) ? dp[i % 2][j] + 1 : max(dp[i % 2][j+1], dp[!(i % 2)][j]);
            }
        }

        return dp[n % 2][m];
    }
};