class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int &a, int &b){
            int left = __builtin_popcount(a);
            int right = __builtin_popcount(b);
            if(left != right) return left < right;
            else return a < b;
        });
        return arr;
    }
};