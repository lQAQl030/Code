class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        while(!nums2.empty()){
            nums1.push_back(nums2.back());
            nums2.pop_back();
        }
        sort(nums1.begin(), nums1.end());
        int half = nums1.size() / 2;
        if(nums1.size() % 2 == 1){
            return (double)nums1[half];
        }else{
            return (double)(nums1[half - 1] + nums1[half]) / 2;
        }
    }
};