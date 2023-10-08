class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX, n = words.size();
        for(int i = 0 ; i < n ; i++) if(words[i] == target) ans = min({ans, abs(i - startIndex), n - abs(i - startIndex)});
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};