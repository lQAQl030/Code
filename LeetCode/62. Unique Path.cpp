class Solution {
public:

    int factorial(int n, int m){
        double sum = 1;
        for(int i = 0 ; i < m ; i++){
            sum *= n - i;
            sum /= i + 1;
        }
        return (int)sum;
    }

    int uniquePaths(int m, int n) {
        return factorial(m + n - 2, min(m,n)-1);
    }
};