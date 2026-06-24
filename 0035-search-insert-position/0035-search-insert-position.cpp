class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            // Find the middle element safely to prevent overflow
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return mid; // Found the exact target!
            } 
            else if (nums[mid] < target) {
                low = mid + 1; // Target is in the right half
            } 
            else {
                high = mid - 1; // Target is in the left half
            }
        }
        
        // If the target isn't found, 'low' will naturally point 
        // to the exact index where the target should be inserted!
        return low;
    }
};