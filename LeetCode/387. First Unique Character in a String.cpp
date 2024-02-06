class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> c(26, INT_MAX);
        for(int i = 0 ; i < s.length() ; i++){
            int num = s[i] - 'a';
            if(c[num] == INT_MAX) c[num] = i;
            else c[num] = 1000000;
        }

        int low = *min_element(c.begin(), c.end());
        return (low == 1000000 || low == INT_MAX) ? -1 : low;
    }
};