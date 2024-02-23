class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        if(prices.size() == 1) return (money >= prices[0]) ? money - prices[0] : money; 

        sort(prices.begin(), prices.end());
        int sum = prices[0] + prices[1];
        return (money >= sum) ? money - sum : money;
    }
};