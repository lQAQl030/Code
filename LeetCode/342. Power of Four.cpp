class Solution {
public:
    bool isPowerOfFour(int n) {
        double a = log(n) / log(4);
        if(fmod(a,1.0) == 0) return true;
        else return false;
    }
};