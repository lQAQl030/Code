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

//second try
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int n = s.size();
        int i = n - 1;
        while(i >= 0 && s[i] == ' ') i--;
        while(i >= 0 && s[i--] != ' ') count++;
        return count;
    }
};