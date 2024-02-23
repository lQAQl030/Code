class Solution {
public:
    struct cmp{
        bool operator()(vector<int>& lhs, vector<int>& rhs) const{
            return lhs[1] < rhs[1];
        }
    };

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        int i = 1;
        int f = 0;
        int ans = 0;
        while(i < intervals.size()){
            if(intervals[i][0] < intervals[f][1]) ans++;
            else{
                f = i;
            }
            i++;
        }
        return ans;
    }
};