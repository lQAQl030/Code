class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int count = 0;
        int n = nums.size();
        for (size_t i = 0; i < n; i++)
        {
            if (nums[i] == val)
            {
                count++;
            }
            else
            {
                nums[i - count] = nums[i];
            }
        }
        return n - count;
    }
};