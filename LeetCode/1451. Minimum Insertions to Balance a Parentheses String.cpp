class Solution {
public:
    int minInsertions(string s) {
        stack<char> left;
        int sum = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                left.push('(');
            }else if(s[i] == ')'){
                if(i+1 < s.size() && s[i+1] == ')'){
                    if(left.empty()){
                        sum++;
                        i++;
                        continue;
                    }
                    left.pop();
                    i++;
                }else{
                    if(left.empty()){
                        sum += 2;
                        continue;
                    }else{
                        sum++;
                        left.pop();
                    }
                }
            }
        }
        while(!left.empty()){
            sum += 2;
            left.pop();
        }
        return sum;
    }
};