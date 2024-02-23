class Solution {
public:
    void solve(string str, string digits, vector<string>& letters, vector<string>& ans){
        if(digits.empty()){
            ans.push_back(str);
            return;
        }
        for(char c : letters[digits[0] - '2']){
            solve(str + c, digits.substr(1), letters, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> letters{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        solve("", digits, letters, ans);
        return ans;
    }
};