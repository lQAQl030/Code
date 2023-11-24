class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        sort(piles.begin(), piles.end());
        int now = piles.size();
        for(int i = 0 ; i < piles.size()/3 ; i++){
            now -= 2;
            ans += piles[now];
        }
        return ans;
    }
};