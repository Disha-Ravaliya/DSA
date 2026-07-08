class Solution {
public:

    void helper(int num , int &count){


        if(num == 0){
            return ;
        }

        if(num % 2 == 0){
            int n = num/2;
            count++;
            helper(n,count);
        }else{
            count++;
            helper(num-1,count);
        }

    }
    int numberOfSteps(int num) {
        int count =0;
        
        helper(num,count);
        return count;
    }
};