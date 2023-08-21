class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 1;
        }
        int tmp = 0;
        int space = 1;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[tmp] == nums[i])
            {
                space = tmp + 1;
            }
            else
            {
                nums[space] = nums[i];
                tmp = space;
                space++;
            }
        }
        return space;
    }
};