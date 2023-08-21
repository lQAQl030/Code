class Solution
{
public:
    char pair_system(char right)
    {
        switch (right)
        {
        case ')':
            return '(';
            break;
        case ']':
            return '[';
            break;
        case '}':
            return '{';
            break;
        default:
            break;
        }
        return ' ';
    }

    bool isValid(string s)
    {
        if (s.size() == 1)
        {
            return false;
        }
        vector<char> stack;

        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
            case '[':
            case '{':
                stack.push_back(s[i]);
                break;
            case ')':
            case ']':
            case '}':
                if (stack.empty())
                {
                    return false;
                }
                
                if (pair_system(s[i]) == stack.back())
                {
                    stack.pop_back();
                }
                else
                {
                    return false;
                }
                break;
            default:
                break;
            }
        }
        if (!stack.empty())
        {
            return false;
        }

        return true;
    }
};