class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> left;
        string ans = "";
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '('){
                left.push(1);
                if(left.size() > 1) ans += s[i];
            }
            else{
                left.pop();
                if(!left.empty()) ans += s[i];
            }
        }
        return ans;
    }
};