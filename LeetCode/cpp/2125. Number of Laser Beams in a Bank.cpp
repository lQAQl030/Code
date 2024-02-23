class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, now = 0, sum = 0;
        for(string &s : bank){
            now = 0;
            for(char &c : s){
                if(c == '1') now++;
            }
            sum += prev * now;
            if(now != 0) prev = now;
        }
        return sum;
    }
};