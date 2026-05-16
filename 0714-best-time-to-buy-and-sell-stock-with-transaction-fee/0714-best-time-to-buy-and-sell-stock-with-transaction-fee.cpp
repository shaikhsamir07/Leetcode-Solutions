class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int hold = -prices[0]; // Buying stock
        int cash = 0;          // No stock in hand

        for (int i = 1; i < prices.size(); i++) {

            // Max profit after buying/holding
            hold = max(hold, cash - prices[i]);

            // Max profit after selling
            cash = max(cash, hold + prices[i] - fee);
        }

        return cash;
    }
};