class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.begin(), happiness.end(), greater());
        for(int i = 0 ; i < k ; i++){
            int now = happiness[i] - i;
            ans += (now >= 0) ? now : 0;
        }
        return ans;
    }
};