class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.length(); i++) {

            // s[i] -> t[i] mapping
            if (mp1.find(s[i]) != mp1.end()) {
                if (mp1[s[i]] != t[i])
                    return false;
            }
            else {
                mp1[s[i]] = t[i];
            }

            // t[i] -> s[i] mapping
            if (mp2.find(t[i]) != mp2.end()) {
                if (mp2[t[i]] != s[i])
                    return false;
            }
            else {
                mp2[t[i]] = s[i];
            }
        }

        return true;
    }
};