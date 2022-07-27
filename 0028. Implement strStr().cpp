class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
        {
            return -1;
        }

        int k = 0;
        for (size_t i = 0; i < haystack.length(); i++)
        {
            if (haystack[i] == needle[0])
            {
                for (size_t j = 0; j < needle.length(); j++)
                {
                    if (haystack[i + j] != needle[j])
                    {
                        break;
                    }
                    if (j + 1 == needle.length())
                    {
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};