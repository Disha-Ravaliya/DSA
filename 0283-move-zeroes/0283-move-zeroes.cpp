class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int len = nums.size();
        int left = 0;

        while (left < len) {

            if (nums[left] != 0) {
                left++;
                continue;
            }

            int right = left + 1;

            while (right < len && nums[right] == 0) {
                right++;
            }

            if (right == len) {
                break;
            }

            swap(nums[left], nums[right]);
        }
    }
};