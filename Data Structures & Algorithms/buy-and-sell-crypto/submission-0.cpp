class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            // Update minimum price
            minPrice = min(minPrice, price);

            // Calculate profit if sold today
            int profit = price - minPrice;

            // Update max profit
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};