class Solution {

// here use 2 pointer bcz we need to check for isalpha and isspace so do this , if only need reverse then use reverse function 

// isalnum ,isalpha , tolower

public:
    bool isPalindrome(string s) {
        int len = s.size();
        if(len <=1){
            return true;
        }
        string copy = s;
        int left = 0;
        int right = len -1 ;

        while(left < right){
           
                if(!isalnum(s[left])){
                    left++;
                }else if(!isalnum(s[right])){
                    right--;
                }
                else {
                   if(tolower(s[left]) != tolower(s[right])){ // here are dif if upper nd lower then convert into tolower 

                    return false;
                   }else{

                   //swap(s[left], s[right]);
                    left++;
                    right--;
                   }
                }
            
        }
        

        return true;;
    }
};