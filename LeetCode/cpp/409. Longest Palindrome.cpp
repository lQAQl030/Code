class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(char c : s) mp[c]++;

        int ans = 0;
        int odd = 0;
        for(auto &[c, i] : mp){
            if(i % 2 != 0) odd++;
            ans += i;
        }
        if(odd > 1) ans -= (odd-1);
        return ans;
    }
};