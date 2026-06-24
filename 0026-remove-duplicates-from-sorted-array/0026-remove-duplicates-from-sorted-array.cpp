class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        std::set<int> s;
        s.insert(nums.begin(), nums.end());
        
        
        int i = 0;
        for (int val : s) {
            nums[i] = val;
            i++;
        }
        
        
        return s.size();
    }
};