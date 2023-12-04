class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int max_num = '/';
        for(int i = 1 ; i < num.size() - 1 ; i++){
            if(num[i-1] == num[i] && num[i] == num[i+1]){
                max_num = (num[i] > max_num) ? num[i] : max_num;
            }
        }
        if(max_num == '/') return "";
        for(int i = 0 ; i < 3 ; i++){
            ans += max_num;
        }
        return ans;
    }
};