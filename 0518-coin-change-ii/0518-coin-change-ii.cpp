#include <vector>

class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        // Changed to unsigned int to safely handle intermediate overflows
        std::vector<unsigned int> dp(amount + 1, 0);
        
        dp[0] = 1;
        
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }
        
        // Cast back to int for the return type
        return (int)dp[amount];
    }
};
