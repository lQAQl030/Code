class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        char color_now = colors[0];
        int time_now = neededTime[0];
        int cost = 0;
        for(int i = 1 ; i < n ; i++){
            if(color_now == colors[i]){
                if(time_now < neededTime[i]){
                    cost += time_now;
                    time_now = neededTime[i];
                }else{
                    cost += neededTime[i];
                }
            }else{
                color_now = colors[i];
                time_now = neededTime[i];
            }
        }
        return cost;
    }
};