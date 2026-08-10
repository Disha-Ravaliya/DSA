class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        unordered_set<string> start;

        // Store all starting cities
        for (auto path : paths) {
            start.insert(path[0]);
        }

        // Find city which is never a starting city
        for (auto path : paths) {
            if (start.find(path[1]) == start.end()) {
                return path[1];
            }
        }

        return "";
    }
};