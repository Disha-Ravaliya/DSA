#include <numeric>
#include <vector>

class Solution {
public:
    /**
     * @brief Finds the missing number in an array containing distinct numbers
     * from 0 to n.
     *
     * METHODOLOGY: Mathematical Sum Formula
     * 1. The expected sum of numbers from 0 to n is given by the formula: (n *
     * (n + 1)) / 2.
     * 2. We calculate the actual sum of the elements present in the vector
     * using std::accumulate.
     * 3. The difference between the expected total sum and the actual sum
     * yields the missing number.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(n) -> We traverse the array once to compute the sum.
     * - Space Complexity: O(1) -> Only a few variables are used, requiring
     * constant extra space.
     */
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();

        // Calculate the sum of elements in the given vector
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        // Calculate the expected sum of numbers from 0 to n using Gauss's
        // formula
        int naturalnum = (n * (n + 1)) / 2;

        // The missing number is the difference between the expected sum and the
        // actual sum
        return naturalnum - sum;
    }
};