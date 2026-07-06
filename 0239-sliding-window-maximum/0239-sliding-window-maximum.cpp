class Solution {
public:
    /**
     * @brief Finds the maximum element in each sliding window of size k.
     * 
     * METHODOLOGY: Monotonic Deque
     * We use a double-ended queue (deque) to store the *indices* of the elements.
     * The deque is maintained such that the values corresponding to the indices 
     * are strictly in decreasing order. This guarantees that the index at the 
     * front of the deque always points to the maximum element in the current window.
     * 
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(n) -> Each element's index is pushed and popped from 
     *   the deque at most once.
     * - Space Complexity: O(k) -> The deque will hold at most 'k' indices at any time.
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        // 1. Process the very first window (first 'k' elements)
        for(int i =0; i <k; i ++){
            // Remove indices of smaller elements from the back. 
            // They are useless because the current element is larger and comes later.
            while(dq.size() >0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            // Store the index, not the value
            dq.push_back(i);
        }

        // 2. Process the remaining elements of the array
        for(int i =k; i <nums.size(); i++){
            // The front of the deque always holds the index of the maximum 
            // element for the *previous* window.
            ans.push_back(nums[dq.front()]);

            // Remove elements from the front if they have slid out of the 
            // current window bounds (i.e., index is <= i - k)
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front(); // its not from cuu window 
            }

            // Maintain the monotonic decreasing property for the new element
            while(dq.size() >0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // 3. Add the maximum element for the very last window
        ans.push_back(nums[dq.front()]);

        return ans;
        
    }
};