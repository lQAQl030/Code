class Solution {
public:

    int** pascal(int n){
        int** arr = new int*[n];
        for(int i = 0 ; i < n ; i++){
            arr[i] = new int[n];
            arr[0][i] = 1;
        }
        for(int i = 0 ; i < n ; i++) arr[i][0] = 1;
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < n-i ; j++){
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }

        return arr;
    }

    vector<int> getRow(int rowIndex) {
        int** arr = pascal(rowIndex+1);
        int row = rowIndex, col = 0;
        vector<int> ans;
        while(row >= 0){
            ans.push_back(arr[row][col]);
            row--; col++;
        }
        return ans;
    }
};