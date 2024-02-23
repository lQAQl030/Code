class Solution {
public:
    bool halvesAreAlike(string s) {
        int left = 0, right = 0;
        int i = 0, j = s.size() - 1;
        while(i < j){
            switch(s[i++]){
                case 'a': case 'e': case 'i': case 'o': case 'u':
                case 'A': case 'E': case 'I': case 'O': case 'U':
                    left++;
                    break;
                default:
                    break;
            }
            switch(s[j--]){
                case 'a': case 'e': case 'i': case 'o': case 'u':
                case 'A': case 'E': case 'I': case 'O': case 'U':
                    right++;
                    break;
                default:
                    break;
            }
        }
        return left == right;
    }
};