class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int tail = digits.size() - 1;
        while (tail >= 0)
        {
            if (++digits[tail] != 10)
            {
                return digits;
            }
            digits[tail] = 0;
            tail--;
        }
        if (tail == -1)
        {
            digits.insert(digits.begin(), 1);
            return digits;
        }
        return digits;
    }
};