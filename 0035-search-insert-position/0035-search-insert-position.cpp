class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0 ;
        
        int len = nums.size();
        
        for(int i = 0 ; i <len ; i++){

            if(nums[i] == target){
                return i ;
            }
            
            

            
        }
        for(int j =0 ;j <len ; j++){
            if(nums[j] >target){
                return j;
            }
            
        }
        return len;
        
    }
};