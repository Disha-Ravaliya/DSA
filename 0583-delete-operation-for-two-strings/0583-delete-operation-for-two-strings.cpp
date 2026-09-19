
class Solution {
public:

    int tab(string word1, string word2, int i, int j,
            vector<vector<int>>& dp) {

        // Base case
        if(i < 0 || j < 0) {
            return 0;
        }

        // Already calculated
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // Characters match
        if(word1[i] == word2[j]) {
            return dp[i][j] =
                1 + tab(word1, word2, i-1, j-1, dp);
        }

        // Characters don't match
        else {
            return dp[i][j] =
                max(tab(word1, word2, i-1, j, dp),
                    tab(word1, word2, i, j-1, dp));
        }
    }

    int minDistance(string word1, string word2) {

        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Find LCS
        int lcs = tab(word1, word2, m-1, n-1, dp); // we start from bottom to up ...

        // Convert LCS into minimum deletions
        int a = m - lcs;
        int b = n - lcs;

        return a + b;
    }
};

