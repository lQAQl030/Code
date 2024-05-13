class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), half = m / 2;
        for(int i = 0 ; i < m ; i++){
            if(grid[i][0] == 0){
                for(int &num : grid[i]) num ^= 1;
            }
        }

        cout << "1st\n";
        for(auto v : grid){
            for(int i : v){
                cout << i << " ";
            }
            cout << endl;
        }

        for(int j = 0 ; j < n ; j++){
            int zeros = 0;
            for(int i = 0 ; i < m ; i++){
                if(grid[i][j] == 0) zeros++;
                if(zeros > half){
                    for(int i = 0 ; i < m ; i++) grid[i][j] ^= 1;
                    break;
                }
            }
        }

        cout << "2nd\n";
        for(auto v : grid){
            for(int i : v){
                cout << i << " ";
            }
            cout << endl;
        }

        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            int curr = 0;
            for(int j = 0 ; j < n ; j++){
                curr += grid[i][j] << n - j - 1;
            }
            ans += curr;
        }
        return ans;
    }
};