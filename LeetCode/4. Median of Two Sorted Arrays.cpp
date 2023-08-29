class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() < nums2.size()) nums1.swap(nums2);
        while(!nums2.empty()){
            nums1.push_back(nums2.back());
            nums2.pop_back();
        }
        sort(nums1.begin(), nums1.end());
        if(nums1.size() % 2 == 1){
            double sum = nums1[nums1.size() / 2];
            return sum;
        }else{
            double sum = (double)(nums1[(nums1.size() / 2) - 1] + nums1[nums1.size() / 2]) / 2;
            return sum;
        }
    }
};