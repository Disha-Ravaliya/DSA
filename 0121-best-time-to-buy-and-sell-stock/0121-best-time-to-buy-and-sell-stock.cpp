class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int mini = prices[0];
        int profit = 0;
        
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < mini) {
                mini = prices[i]; // Update minimum price seen so far
            } else {
                profit = std::max(profit, prices[i] - mini); // Calculate max profit
            }
        }
        return profit;
    }
};