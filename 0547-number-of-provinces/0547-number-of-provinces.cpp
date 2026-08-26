class Solution {
public:
    /**
     * @brief Recursive helper function to traverse a connected component using
     * DFS.
     * @param curr The index of the current city we are visiting.
     * @param rooms The adjacency list representing connections between cities.
     * @param visited Boolean array to track which cities have been visited.
     */
    void helper(int curr, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[curr] = true;

        for (const auto next : rooms[curr]) {
            if (!visited[next]) {
                helper(next, rooms, visited);
            }
        }
    }

    /**
     * @brief Converts an adjacency matrix into an adjacency list
     * representation.
     * @param isConnected The n x n matrix where isConnected[i][j] == 1 means i
     * and j are connected.
     * @return Adjacency list representation of the undirected graph.
     */
    vector<vector<int>> transformAdj(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            // Start j from i + 1 to avoid duplicate edges and self-loops (i ==
            // j)
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    ans[i].push_back(j);
                    ans[j].push_back(i);
                }
            }
        }
        return ans;
    }

    /**
     * @brief Finds the total number of connected components (provinces) in the
     * graph (LeetCode 547).
     *
     * METHODOLOGY: Graph Connected Components (DFS)
     * 1. Transform the input adjacency matrix into an adjacency list for easier
     * traversal.
     * 2. Iterate through all nodes (cities) from 0 to n - 1.
     * 3. Whenever an unvisited node is found, increment the province counter
     * and use DFS to visit and mark all nodes connected to it in the same
     * province.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(n^2) where n is the number of cities. We spend
     * O(n^2) converting the matrix, and O(V + E) = O(n + n^2) during the DFS
     * traversals.
     * - Space Complexity: O(n^2) to store the adjacency list representation,
     * plus O(n) for the visited array and the recursion call stack.
     */
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj = transformAdj(isConnected);
        int n = adj.size();
        vector<bool> visited(n, false);

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                helper(i, adj, visited);
            }
        }
        return count;
    }
};