class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        int left= 0;
        int right = len-1;

        while(left <right){
            swap(s[left],s[right]);
            left++;
            right--;
        }

        
    }
};