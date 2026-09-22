
class Solution {
public:

    int solve(vector<int>& nums, int i, int j,
              vector<vector<int>>& dp) {

        // Only one number left
        if (i == j) {
            return nums[i];
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Take left number
        int left = nums[i] - solve(nums, i + 1, j, dp);

        // Take right number
        int right = nums[j] - solve(nums, i, j - 1, dp);

        return dp[i][j] = max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int difference = solve(nums, 0, n - 1, dp);

        return difference >= 0;
    }
};

