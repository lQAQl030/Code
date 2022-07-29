class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (size_t i = 0; i < n; i++)
        {
            nums1.insert(lower_bound(nums1.begin(), nums1.begin() + m + i, nums2[i]), nums2[i]);
            nums1.pop_back();
        }
    }
};