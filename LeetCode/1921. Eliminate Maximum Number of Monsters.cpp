class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        for(int i = 0 ; i < dist.size() ; i++){
            dist[i] = (dist[i]-1) / speed[i] + 1;
        }
        sort(dist.begin(), dist.end());
        int count = 0;
        for(int i = 0 ; i < dist.size() ; i++){
            count++;
            if(count > dist[i]) return dist[i];
        }
        return count;
    }
};