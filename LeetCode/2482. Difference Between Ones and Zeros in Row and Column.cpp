class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> onesRow, onesCol(n, 0);
        for(int i = 0 ; i < m ; i++){
            int ones = 0;
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    ones++;
                    onesCol[j]++;
                }
            }
            onesRow.push_back(ones);
        }

        vector<vector<int>> diff(m, vector<int>(n));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                diff[i][j] = 2*onesRow[i] + 2*onesCol[j] - m - n;
            }
        }
        return diff;
    }
};