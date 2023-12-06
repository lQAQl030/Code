class Solution {
public:
    int totalMoney(int n) {
        int arr[7] = {1,2,3,4,5,6,7};
        int count = 0;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += arr[count++]++;
            if(count == 7) count = 0;
        }
        return sum;
    }
};