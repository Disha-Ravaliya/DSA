class Solution {
public:
    /**
     * @brief Finds the maximum product of two elements in an array.
     *
     * METHODOLOGY: Linear Scan
     * We maintain two variables to track the largest and second largest
     * elements in the array. As we iterate through the array, we update these
     * two variables whenever we find a number larger than the current maximum.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(n) -> Single pass through the array.
     * - Space Complexity: O(1) -> Only uses two variables.
     */
    int maxProduct(vector<int>& nums) {
        int max1 = 0; // Will hold the largest element
        int max2 = 0; // Will hold the second largest element

        for (int num : nums) {
            if (num > max1) {
                // If the current number is greater than max1,
                // the old max1 becomes the new max2, and max1 becomes num.
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                // If it's not greater than max1, but greater than max2,
                // update max2.
                max2 = num;
            }
        }

        // Return the product of the two largest elements (minus 1 each, as per
        // LeetCode 1464)
        return (max1 - 1) * (max2 - 1);
    }
};