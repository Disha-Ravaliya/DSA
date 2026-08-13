class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        // If they cannot be made by repeating the same pattern
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // GCD of their lengths gives the length of answer
        int n = str1.length();
        int m = str2.length();

        int len = gcd(n, m);

        return str1.substr(0, len);
    }
};