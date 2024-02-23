class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev = 0, pprev = 0;
        for(int i = 2 ; i < cost.size() + 1 ; i++){
            int temp = prev;
            prev = min(prev + cost[i-1], pprev + cost[i-2]);
            pprev = temp;
        }
        return prev;
    }
};