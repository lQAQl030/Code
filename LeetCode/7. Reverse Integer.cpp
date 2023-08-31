class Solution {
public:
    int reverse(int x) {
        char imax[10] = {'2','1','4','7','4','8','3','6','4','7'};
        bool check[10];
        memset(check, false, 10);
        bool neg = false;
        char reverse[10];
        memset(reverse, '0', 10);

        //check negative
        if(x < 0){
            if(x == -INT_MAX-1) return 0;
            neg = true;
            x *= -1;
            imax[9] = '8';
        }

        //count raise to where
        int p = -1;
        for(int i = x ; i > 0 ; i /= 10){
            p++;
        }

        //put digit in reverse[]
        for(int i = x ; i > 0 ; i /= 10){
            reverse[9 - p] = i % 10 + '0';
            p--;
        }
        
        //check limit
        if(reverse[0] > imax[0]) return 0;
        else if(reverse[0] == imax[0]) check[0] = true;
        for(int i = 1 ; i < 10 ; i++){
            if(check[i-1]){
                if(reverse[i] > imax[i]) return 0;
                else if(reverse[i] == imax[i]) check[i] = true;
            }else break;
        }

        //count sum
        int sum = 0;
        for(int i = 0 ; i < 10 ; i++){
            sum += (reverse[i] - '0') * pow(10,9-i);
        }
        if(neg) sum *= -1;
        return sum;
    }
};