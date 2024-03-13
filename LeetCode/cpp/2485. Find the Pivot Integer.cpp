class Solution {
public:
    int pivotInteger(int n) {
        int left = ((1 + n) * n) / 2, right = n;
        int now = n;
        while(now >= 1){
            if(left == right) return now;
            else{
                left -= now;
                now--;
                right += now;
            }
        }
        return -1;
    }
};