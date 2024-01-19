class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i = 1 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                int left = 100000, mid = 100000, right = 100000;
                if(j-1 >= 0) left = matrix[i-1][j-1];
                mid = matrix[i-1][j];
                if(j+1 < matrix[0].size()) right = matrix[i-1][j+1];
                
                int min_path = min(left, min(mid, right));
                matrix[i][j] += min_path;
            }
        }

        int min_path = INT_MAX;
        for(int &i : matrix.back()){
            min_path = min(min_path, i);
        }
        return min_path;
    }
};