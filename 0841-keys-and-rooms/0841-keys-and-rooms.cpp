class Solution {
public:
    /**
     * @brief Recursive helper function to explore rooms using Depth-First
     * Search (DFS).
     * @param curr The index of the current room we are visiting.
     * @param rooms The adjacency list representing keys inside each room.
     * @param visited Boolean array to keep track of unlocked/visited rooms.
     */
    void helper(int curr, vector<vector<int>>& rooms, vector<bool>& visited) {
        // Mark the current room as visited
        visited[curr] = true;

        // Iterate through all the keys found in the current room
        for (const auto next : rooms[curr]) {
            // Only recurse if the target room hasn't been unlocked yet
            if (!visited[next]) {
                helper(next, rooms, visited);
            }
        }
    }

    /**
     * @brief Determines if all rooms can be visited starting from room 0
     * (LeetCode 841).
     *
     * METHODOLOGY: Graph Traversal (Depth-First Search)
     * 1. Treat each room as a node in a directed graph and the keys as edges.
     * 2. Start a DFS traversal from room 0, marking every reachable room in a
     * visited array.
     * 3. After traversal completes, verify if all rooms have been visited.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(N + E), where N is the number of rooms and E is the
     * total number of keys. We visit every reachable room once and examine
     * every key once.
     * - Space Complexity: O(N) to store the 'visited' array and for the
     * recursion call stack in the worst-case scenario (a single linear chain of
     * rooms).
     */
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        // Start exploring from Room 0 (always unlocked initially)
        helper(0, rooms, visited);

        // Check if every room was reached
        bool result = true;
        for (const auto r : visited) {
            result = (result && r);
            // Optional optimization: if 'r' is false, you can break early
        }

        return result;
    }
};