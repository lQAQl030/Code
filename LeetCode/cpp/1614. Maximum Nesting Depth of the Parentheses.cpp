class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int max_count = 0;
        for(char c : s){
            if(c == '(') count++;
            else if (c == ')') count--;
            max_count = max(max_count, count);
        }
        return max_count;
    }
};