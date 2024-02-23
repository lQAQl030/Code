class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string sub, ans;
        while(getline(ss, sub, ' ')){
            for(int i = sub.length() - 1 ; i >= 0 ; i--){
                ans += sub[i];
            }
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};