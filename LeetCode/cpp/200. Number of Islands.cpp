class Solution {
public:
    int n = 0, m = 0;

    void island(int i, int j, vector<vector<char>>& grid){
        if(i < 0 || j < 0 || i >= n || j >= m) return;
        if(grid[i][j] != '1') return;
        grid[i][j] = '#';
        island(i-1, j, grid);
        island(i+1, j , grid);
        island(i, j-1, grid);
        island(i, j+1, grid);
    }
    

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int islands = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    island(i, j, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};