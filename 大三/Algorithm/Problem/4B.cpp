#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid;
    for(int i = 0 ; i < n ; i++){
        vector<int> row(m);
        for(int j = 0 ; j < m ; j++){
            cin >> row[j];
        }
        grid.push_back(row);
    }


    grid[0][0] = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(i == 0 && j == 0) continue;
            int left = (j-1 >= 0) ? grid[i][j-1] + grid[i][j] : INT_MIN;
            int up = (i-1 >= 0) ? grid[i-1][j] + 2 * grid[i][j] : INT_MIN;
            int left_up = (i-1 >= 0 && j-1 >= 0) ? grid[i-1][j-1] + 4 * grid[i][j] : INT_MIN;
            grid[i][j] = max(left, max(up, left_up));
        }
    }

    cout << grid[n-1][m-1];

    return 0;
}