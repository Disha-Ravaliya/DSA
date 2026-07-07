class Solution {
public:
    /**
     * @brief Finds the minimum window substring of s that contains all characters in t.
     * 
     * METHODOLOGY: Sliding Window (Two Pointers)
     * 1. 'need' map stores the frequency of characters required from string t.
     * 2. 'window' map tracks characters currently inside the sliding window.
     * 3. 'formed' tracks how many unique characters meet the required frequency count.
     * 4. Once 'formed == required', the window is valid, and we shrink it from the left
     *    to find the smallest possible length.
     * 
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(|s| + |t|) -> Each character is visited at most twice.
     * - Space Complexity: O(|t|) -> For the character frequency maps.
     */
    string minWindow(string s, string t) {

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        // Populate the frequency map of required characters in t
        for(char c : t)
            need[c]++;

        int required = need.size(); // Number of unique characters that must be present
        int formed = 0;             // Number of characters currently meeting frequency requirements

        int left = 0;
        int right = 0;

        int minLen = INT_MAX;
        int start = 0; // Tracks the starting position of the minimum window

        // Expand the window by moving the 'right' pointer
        while(right < s.size()) {

            char c = s[right];
            window[c]++;

            // If the current character is required and its count matches, increment 'formed'
            if(need.count(c) && window[c] == need[c])
                formed++;

            // Shrink the window while it is valid (contains all characters from t)
            while(formed == required) {

                // Update the global minimum length and starting index if current window is smaller
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove the character at 'left' from the window
                char ch = s[left];
                window[ch]--;

                // If the character removed is required and its count falls below the target,
                // the window is no longer valid, so decrement 'formed'
                if(need.count(ch) && window[ch] < need[ch])
                    formed--;

                left++; // Shrink window from the left
            }

            right++; // Expand window to the right
        }

        // Return the substring if a valid window was found, otherwise return empty string
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};