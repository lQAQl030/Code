class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int zero = 0, one = 0;
        for(char &c : s){
            if(c == '0') zero++;
            else one++;
        }
        
        string ans;
        while(one > 1){
            ans += '1';
            one--;
        }
        while(zero > 0){
            ans += '0';
            zero--;
        }
        return ans + '1';
    }
};