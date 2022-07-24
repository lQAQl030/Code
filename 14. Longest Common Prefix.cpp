class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 1)
        {
            return strs[0];
        }

        string ans = {};

        for (size_t i = 0; i < 200; i++)
        {
            ans.push_back(strs[0][i]);
            for (size_t j = 0; j < strs.size(); j++)
            {
                if (strs[j].empty())
                {
                    return {};
                }
                if (strs[j][i] != ans[i] || strs[j].size() <= i)
                {
                    ans.pop_back();
                    return ans;
                }
            }
        }
        return ans;
    }
};