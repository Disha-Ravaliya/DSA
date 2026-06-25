class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int llen = s.length();
        int len = t.length();
        if(len != llen){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t){
            return true;
        }
        return false;
    }
};