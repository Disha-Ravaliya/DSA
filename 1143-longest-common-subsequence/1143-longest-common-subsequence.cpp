class Solution {
public:
    int lcs(const string& text1, const string& text2, int i, int j,
            vector<vector<int>>& dp) {
        int n = text1.size();
        int m = text2.size();
        if (i >= n || j >= m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + lcs(text1, text2, i + 1, j + 1, dp);
        } else {
            return dp[i][j] = max(lcs(text1, text2, i + 1, j, dp),
                                  lcs(text1, text2, i, j + 1, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return lcs(text1, text2, 0, 0, dp);
    }
};