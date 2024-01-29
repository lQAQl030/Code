class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int mod = numRows * 2 - 2; 
        string ans;
        for(int row = 0 ; row < numRows ; row++){
            if(row == 0 || row == numRows - 1){
                for(int i = row ; i < s.size() ; i += mod){
                    ans.push_back(s[i]);
                }
            }else{
                for(int i = row ; i < s.size() ; i += mod){
                    ans.push_back(s[i]);
                    int modded = i % mod;
                    int diff = mod - modded;
                    if(i - modded + diff < s.size()) ans.push_back(s[i - modded + diff]);
                }
            }
        }
        return ans;
    }
};