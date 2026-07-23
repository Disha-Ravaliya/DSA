impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let amt = amount as usize;
        // Create a DP vector of size amount + 1, initialized with a value representing infinity (amount + 1)
        let mut dp = vec![amt + 1; amt + 1];
        
        // Base case: 0 coins are needed to make an amount of 0
        dp[0] = 0;

        // Iterate through every amount from 1 to target amount
        for i in 1..=amt {
            for &coin in &coins {
                let c = coin as usize;
                // If the coin can be used for the current amount
                if i >= c {
                    dp[i] = std::cmp::min(dp[i], 1 + dp[i - c]);
                }
            }
        }

        // If dp[amount] is still greater than amount, it means the amount cannot be formed
        if dp[amt] > amt {
            -1
        } else {
            dp[amt] as i32
        }
    }
}