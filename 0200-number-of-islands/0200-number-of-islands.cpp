class Solution {
public:
    void dfs(int i, int j, const vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {

        // Out of bounds
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;

        // If water or already visited
        if (grid[i][j] == '0' || visited[i][j])
            return;

        // Mark current land as visited
        visited[i][j] = true;

        // Down
        dfs(i + 1, j, grid, visited);

        // Up
        dfs(i - 1, j, grid, visited);

        // Right
        dfs(i, j + 1, grid, visited);

        // Left
        dfs(i, j - 1, grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Found a new island
                if (grid[i][j] == '1' && !visited[i][j]) {

                    ans++;

                    // Visit the complete island
                    dfs(i, j, grid, visited);
                }
            }
        }

        return ans;
    }
};