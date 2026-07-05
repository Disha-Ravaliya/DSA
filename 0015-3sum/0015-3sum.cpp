class Solution {
public:
    /**
     * @brief Finds all unique triplets in the array which gives the sum of zero.
     * 
     * METHODOLOGY: Sorted Two-Pointer with Set Deduping
     * 1. Sort the input array to enable the two-pointer approach and eliminate 
     *    unstructured duplicate checks.
     * 2. Fix the first element (`nums[i]`) and use an inward two-pointer scan 
     *    (`left` and `right`) to find pairs that complement `nums[i]` to zero.
     * 3. Utilize `std::set` to automatically filter out duplicate triplets.
     * 
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(n^2 * log(k)) -> O(n log n) for sorting + O(n^2) for the 
     *   nested loops, multiplied by log(k) for set insertion overhead (where k is 
     *   the number of unique triplets).
     * - Space Complexity: O(k) -> To store the unique triplets inside the set.
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        // Sorting helps in applying the two-pointer approach linearly
        sort(nums.begin(), nums.end());

        // Set is used here to avoid storing duplicate triplet combinations
        set<vector<int>>v;
        
        // Loop through the array, leaving room for at least a triplet combo (left and right)
        for(int i =0; i <n -2 ; i++){
            int sum = nums[i];      // Fixed element anchorage
            int left = i+1;         // Left pointer starts right after the fixed element
            int right = n-1;        // Right pointer starts at the very end of the array

            // Process pairs tracking towards the center
            while(left <right){
                int mid = nums[left] +nums[right];

                // If a valid triplet is found
                if(sum + mid == 0 ){
                    v.insert({sum,nums[left],nums[right] });
                    left++;         // Contract left boundary
                    right--;        // Contract right boundary
                }else if(sum + mid <0){
                    left++;         // Sum is too small; move left pointer forward to increase value
                }else if(sum + mid >0) {
                    right--;        // Sum is too big; move right pointer backward to decrease value
                }
            }
        
        
        }
        // Convert the set of unique triplets back to standard 2D vector for return
        vector<vector<int>>vv(v.begin(), v.end());
        return vv;
    }
};















// int sum = nums[i];
//         for(int j = i+1 ; j <n-1; j ++){
//             int left =j;
//             for(int k = j+1 ; k <n; k++){
//                 int right = k;
//                 if(sum + nums[left] + nums[right] == 0 && (i !=j) && (i!=k) && (j != k )){
//                     v.insert({sum,nums[left],nums[right]});
//                 }
//             }
//         }