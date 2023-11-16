class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i : arr) if(i > ans) ans++;
        return ans;
    }
};