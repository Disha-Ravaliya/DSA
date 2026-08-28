class Solution {
public:
    void dfs(int node, int &step, vector<bool>& visited,
             vector<vector<int>>& adj, vector<bool>& restricted) {

        if (restricted[node] || visited[node]) {
            return;
        }

        visited[node] = true;
        step++;

        for (auto padoshi : adj[node]) {
            if (!restricted[padoshi] && !visited[padoshi]) {
                dfs(padoshi, step, visited, adj, restricted);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges,
                       vector<int>& restricted) {
        vector<vector<int>> adj(n);

        // Create adjacency list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        // Convert restricted node list into boolean array for O(1) lookups
        vector<bool> isRestricted(n, false);
        for (auto x : restricted) {
            isRestricted[x] = true;
        }

        int step = 0;
        dfs(0, step, visited, adj, isRestricted);

        return step;
    }
};