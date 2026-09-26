class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
         int n = cost.size();
        int prev2 = cost[0]; // Cost if we came from 2 steps back
        int prev1 = cost[1]; // Cost if we came from 1 step back
        
        for (int i = 2; i < n; ++i) {
            int current = cost[i] + std::min(prev1, prev2);
            prev2 = prev1;
            prev1 = current;
        }
        
        // To reach the top floor, we can step from either the last or second-to-last stair
        return std::min(prev1, prev2);
    }
};