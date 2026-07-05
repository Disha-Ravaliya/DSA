class Solution {
public:
    /**
     * @file MoveZeroes.cpp
     * @brief Solution for LeetCode 283: Move Zeroes
     * @details Implements a forward-scanning two-pointer approach ("seek and swap").
     *          'left' finds a zero gap, and 'right' dynamically searches ahead for 
     *          the next available non-zero element to swap into that gap.
     * 
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(n) -> Although there is a nested while loop, the 'right' 
     *   pointer only moves forward and never retreats. Each element is visited a 
     *   maximum of two times.
     * - Space Complexity: O(1) -> Performed entirely in-place.
     */
    void moveZeroes(vector<int>& nums) {

        int len = nums.size();
        int left = 0;

        // Loop handles moving the 'left' pointer to find zero gaps
        while (left < len) {

            // If the current element is already non-zero, it's in the correct position.
            // Advance 'left' and skip the rest of the loop logic.
            if (nums[left] != 0) {
                left++;
                continue;
            }

            // At this point, nums[left] is guaranteed to be 0.
            // Initialize 'right' to look for the next non-zero element right ahead.
            int right = left + 1;

            // Skip over any consecutive zeros using the 'right' pointer.
            while (right < len && nums[right] == 0) {
                right++;
            }

            // If 'right' reached the end of the array, it means there are no more
            // non-zero elements left to swap. The remaining elements are all zeros.
            if (right == len) {
                break;
            }

            // Swap the zero at 'left' with the non-zero element found at 'right'.
            swap(nums[left], nums[right]);
        }
    }
};