class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums,
                                       int indexDiff,
                                       int valueDiff) {

        set<long long> s;

        for(int i = 0; i < nums.size(); i++) {

            long long low = (long long)nums[i] - valueDiff;
            long long high = (long long)nums[i] + valueDiff;

            auto it = s.lower_bound(low);

            if(it != s.end() && *it <= high) {
                return true;
            }

            s.insert(nums[i]);

            if(i >= indexDiff) {
                s.erase(nums[i - indexDiff]);
            }
        }

        return false;
    }
};