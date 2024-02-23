class Solution {
public:
    #define mod 1000000007
    int countHomogenous(string s) {
        int count = 1;
        int streak = 1;
        char temp = s[0];
        for(int i = 1 ; i < s.length() ; i++){
            if(s[i] != temp){
                temp = s[i];
                streak = 1;
                count++;
            }
            else{
                count += streak + 1;
                streak++;
            }
            count %= mod;
        }
        return count;
    }
};