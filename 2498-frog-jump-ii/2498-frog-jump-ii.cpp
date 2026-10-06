class Solution {
public:
    int maxJump(vector<int>& stones) {

        int ans = stones[1] - stones[0];// if only 2 size

        for(int i = 2; i < stones.size(); i++) {

            int jump = stones[i] - stones[i - 2];

            ans = max(ans, jump);
        }

        return ans;
    }
};