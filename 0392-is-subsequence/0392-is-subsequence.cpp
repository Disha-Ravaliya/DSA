class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // Pointer for string s
        int j = 0; // Pointer for string t

        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++; // Match found, move pointer in s
            }
            j++; // Always move pointer in t
        }

        // If i reached the end of s, all characters were found in order
        return i == s.length();
    }
};
