class Solution {
public:
    int myAtoi(string s) {
        deque<char> num;
        bool leading = false;
        bool sign = false;
        bool negative = false;
        bool digit = false;
        for(int i = 0 ; i < s.length() ; i++){
            if(!leading && s[i] == ' ') continue;
            if(!sign && (s[i] == '-' || s[i] == '+')){
                if(s[i] == '-') negative = true;
                leading = sign = true;
                continue;
            }
            if('0' <= s[i] && s[i] <= '9'){
                leading = sign = digit = true;
                num.push_back(s[i]);
            }else if(digit){
                break;
            }else{
                return 0;
            }
        }

        //check limit
        string limit = "2147483647";
        bool check[10];
        memset(check, false, 10);
        bool lead_zero = false;
        while(!lead_zero){
            if(num.front() == '0') num.pop_front();
            else lead_zero = true;
        }
        if(num.size() > 10){
            if(negative) return -INT_MAX-1;
            else return INT_MAX;
        }else if(num.size() == 10){
            if(num[0] > '2'){
                if(negative) return -INT_MAX-1;
                else return INT_MAX;/////////////
            }else if(num[0] == '2'){
                check[0] = true;
            }
            if(negative) limit[9] = '8';
            for(int i = 1 ; i < 10 ; i++){
                if(check[i-1] == true){
                    if(num[i] > limit[i]){
                        if(negative) return -INT_MAX-1;
                        else return INT_MAX;
                    }else if(num[i] == limit[i]){
                        check[i] = true;
                    }else break;
                }else break;
            }
        }

        //add up sum
        int sum = 0;
        for(int i = 0 ; i < num.size() ; i++){
            if(negative) sum -= (num[i]-'0') * pow(10,num.size()-i-1);
            else sum += (num[i]-'0') * pow(10,num.size()-i-1);
        }
        return sum;
    }
};