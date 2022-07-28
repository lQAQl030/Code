class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        bool getword = false;
        for (int i = s.length() - 1; i > -1; i--)
        {

            if (s[i] != ' ')
            {
                getword = true;
                count++;
            }
            else if (getword)
            {
                return count;
            }
            else
            {
                continue;
            }
        }
        return count;
    }
};