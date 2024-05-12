class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n-2;
        vector<vector<int>> ans(m, vector<int>(m));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < m ; j++){
                for(int a = i ; a < i+3 ; a++){
                    for(int b = j ; b < j+3 ; b++){
                        ans[i][j] = max(ans[i][j], grid[a][b]);
                    }
                }
            }
        }
        return ans;
    }
};