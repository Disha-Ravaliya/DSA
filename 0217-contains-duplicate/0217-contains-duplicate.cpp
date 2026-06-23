class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();

        set<int> s;

        for(int x : nums){
            if(s.find(x) != s.end()){
                return true;
            }
            s.insert(x);
        }

        return false;
    }
};