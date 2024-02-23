class Solution {
public:
    void solve(vector<string>& ans, string &s, int l, int r, int &n){
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }
        if(l < n){
            s.push_back('(');
            solve(ans, s, l+1, r, n);
            s.pop_back();
        }
        if(r < l){
            s.push_back(')');
            solve(ans, s, l, r+1, n);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;

        solve(ans,s, 0, 0, n);

        return ans;
    }
};