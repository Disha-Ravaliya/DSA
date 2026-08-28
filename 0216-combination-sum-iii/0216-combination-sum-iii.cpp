class Solution {
public:
    /**
     * @brief Recursive helper function to find all valid combinations of k
     * numbers that sum up to n using numbers from 1 to 9.
     *
     * @param s Current combination path being explored.
     * @param k Number of elements remaining to be chosen in the combination.
     * @param n Remaining sum required to reach the target.
     * @param index Starting number for the current choice (ensures numbers 1-9
     * are used only once and in order).
     * @param result Reference to vector storing all valid combinations.
     */
    void helper(vector<int>& s, int k, int n, int index,
                vector<vector<int>>& result) {

        // Base case: If we have successfully picked 'k' numbers AND their sum
        // equals 'n' (n drops to 0)
        if (k == 0 && n == 0) {
            result.push_back(s); // Store the valid combination
            return;
        }

        // Base case: Prune the search tree if we ran out of numbers (k < 0)
        // or if the sum has exceeded the target (n < 0).
        // Also prune early if k hits 0 while n > 0, or vice versa (though
        // handled by logic).
        if (k < 0 || n < 0) {
            return;
        }

        // Iterate through valid digits from 1 to 9 starting from 'index'
        for (int i = index; i <= 9; i++) {
            // Choose: Add the current number to our combination path
            s.push_back(i);

            // Explore: Recurse with k-1 (one less number needed), n-i (reduced
            // target sum), and i+1 (each number can only be used once, and we
            // move forward).
            helper(s, k - 1, n - i, i + 1, result);

            // Un-choose (Backtrack): Remove the number before exploring the
            // next branch
            s.pop_back();
        }
    }

    /**
     * @brief Main function to solve Combination Sum III (LeetCode 216).
     *
     * METHODOLOGY: Backtracking (Depth-First Search)
     * 1. We explore combinations using digits from 1 to 9.
     * 2. Each digit can be used at most once (`i + 1`).
     * 3. We track how many numbers are left to pick (`k`) and what sum is left
     * to reach (`n`).
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(2^9) in the worst case, as there are only 9 possible
     * digits (1-9) to choose from.
     * - Space Complexity: O(k) for the recursion stack and the temporary
     * combination path 's'.
     */
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> s;

        // Start backtracking with k numbers needed, target sum n, starting
        // digit 1
        helper(s, k, n, 1, result);

        return result;
    }
};