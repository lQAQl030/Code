class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(n, 0);
        vector<int> alpha(26, 0);
        for(int i = 0 ; i < n ; i++){
            int now = s[i] - 'a';
            int lower = max(0, now - k);
            int upper = min(25, now + k);
            for(int j = lower ; j <= upper ; j++){
                dp[i] = max(dp[i], alpha[j] + 1);
            }
            alpha[now] = max(dp[i], alpha[now]);
        }

        int ans = 0;
        for(int i : dp) ans = max(i, ans);
        return ans;
    }
};