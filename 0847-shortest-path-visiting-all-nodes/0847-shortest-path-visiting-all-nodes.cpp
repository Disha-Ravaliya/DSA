class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        // 1. BITMASK EXPLANATION:
        // A bitmask represents the set of nodes we have visited so far using binary bits.
        // For example, if n = 4, a mask of 5 (binary: 0101) means we have visited nodes 0 and 2.
        // fullMask sets all n bits to 1 (e.g., if n = 3, (1 << 3) - 1 = 111 in binary).
        // When our current mask reaches fullMask, it means all nodes have been visited.
        int fullMask = (1 << n) - 1;

        // Queue stores pairs of: {current_node, visited_state_mask}
        queue<pair<int, int>> q;

        // Visited tracking: visited[node][mask] ensures we don't revisit 
        // the same node with the exact same combination of visited nodes.
        vector<vector<bool>> visited(
            n,
            vector<bool>(1 << n, false)
        );

        // Multi-source BFS: Since the shortest path can start at any node,
        // we push every node into the queue as a potential starting point.
        for(int i = 0; i < n; i++) {
            // (1 << i) turns on the i-th bit to mark node i as visited at the start.
            // Example: if i = 2, (1 << 2) is 0100 in binary.
            int mask = (1 << i);

            q.push({i, mask});
            visited[i][mask] = true;
        }

        int steps = 0;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto [node, mask] = q.front();
                q.pop();

                // If the mask matches fullMask (all bits are 1), 
                // it means every node has been visited at least once.
                if(mask == fullMask) {
                    return steps;
                }

                // Explore all neighbors of the current node
                for(auto neighbor : graph[node]) {
                    
                    // BITMASK UPDATE:
                    // mask | (1 << neighbor) takes our current visited state (`mask`) 
                    // and uses a bitwise OR to turn on the bit for the `neighbor` we are stepping into.
                    // Example: if mask is 001 and we visit node 1, 
                    // 001 | (1 << 1) [010] becomes 011 (nodes 0 and 1 visited).
                    int newMask = mask | (1 << neighbor);

                    // If this state (neighbor + newMask) has not been visited yet, process it
                    if(!visited[neighbor][newMask]) {
                        visited[neighbor][newMask] = true;
                        q.push({neighbor, newMask});
                    }
                }
            }

            steps++;
        }

        return 0;
    }
};