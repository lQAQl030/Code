class Solution {
public:
    #define mod 1000000007
    #define llong long long int

    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> dp;
        for(int i : arr) dp[i] = 1;
        llong sum = 0;
        for(int i : arr){
            for(int j : arr){
                if(j > sqrt(i)) break;
                if(i % j == 0 && dp.count(i / j)){
                    llong product = (llong)dp[j] * dp[i / j];
                    if(i / j == j){
                        dp[i] = (dp[i] + product) % mod;
                    }else{
                        dp[i] = (dp[i] + product * 2) % mod;
                    }
                }
            }
            sum = (sum + dp[i]) % mod;
        }

        return sum;
    }
};