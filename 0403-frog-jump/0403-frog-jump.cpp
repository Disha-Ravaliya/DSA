class Solution {
public:

    bool solve(vector<int>& stones,
               int current,
               int prev,
               vector<vector<int>>& dp) {

        // Reached last stone
        if (current == stones.size() - 1) {
            return true;
        }

        // Already calculated this state
        if (dp[current][prev] != -1) {
            return dp[current][prev];
        }

        // Try prev-1, prev, prev+1
        for (int jump = prev - 1;
             jump <= prev + 1;
             jump++) {

            // Jump must be positive
            if (jump <= 0) {
                continue;
            }

            // Calculate next stone position
            int nextPosition = stones[current] + jump;

            // Search for that stone
            for (int i = current + 1;
                 i < stones.size();
                 i++) {

                if (stones[i] == nextPosition) {

                    // Try from next stone
                    if (solve(stones, i, jump, dp)) {

                        dp[current][prev] = 1;
                        return true;
                    }
                }
            }
        }

        // No path works
        dp[current][prev] = 0;
        return false;
    }


    bool canCross(vector<int>& stones) {

        int n = stones.size();

        // dp[current][previous jump]
        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1)
        );

        // Start from stone 0, with previous jump 0
        return solve(stones, 0, 0, dp);
    }
};