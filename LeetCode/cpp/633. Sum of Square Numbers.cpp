class Solution {
public:
    bool judgeSquareSum(int c) {
        int start = 0, end = floor(sqrt(c));
        while(start <= end){
            long sum = (long)start*start + end*end;
            if(sum == c) return true;
            else if(sum > c) end--;
            else if(sum < c) start++;
        }
        return false;
    }
};