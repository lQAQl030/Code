class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;
        if(k <= (1 << (n-2))) return kthGrammar(n-1, k);
        else return kthGrammar(n-1, k - (1 << (n-2))) ^ 1;
    }
};