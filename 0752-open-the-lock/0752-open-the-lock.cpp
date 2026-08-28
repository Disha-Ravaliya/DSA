class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // Convert deadends to a set for O(1) lookup time
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;

        // If the starting combination is blocked, we can never open it
        if(dead.count("0000")) {
            return -1;
        }

        // Initialize BFS with the starting state "0000"
        q.push("0000");
        visited.insert("0000");

        int step = 0;

        while(!q.empty()) {
            int size = q.size();

            // Process all states at the current level (representing one turn/step)
            while(size--) {
                string curr = q.front();
                q.pop();

                // If we reached the target combination, return the number of steps
                if(curr == target) {
                    return step;
                }

                // Try turning each of the 4 wheels
                for(int i = 0; i < 4; i++) {

                    // 1. FORWARD turn (e.g., '0' -> '1', '9' -> '0')
                    string next = curr;
                    if(next[i] == '9') {
                        next[i] = '0';
                    } else {
                        next[i]++;
                    }

                    // Push to queue if valid and unvisited
                    if(!dead.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }

                    // 2. BACKWARD turn (e.g., '0' -> '9', '1' -> '0')
                    next = curr;
                    if(next[i] == '0') {
                        next[i] = '9';
                    } else {
                        next[i]--;
                    }

                    // Push to queue if valid and unvisited
                    if(!dead.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            step++; // Increment step count after finishing the current level
        }

        // If queue empties and target is never reached, it's impossible
        return -1;
    }
};