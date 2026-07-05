class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        set<vector<int>>v;
        
        for(int i =0; i <n -2 ; i++){
            int sum = nums[i];
            int left = i+1;
            int right = n-1;

            while(left <right){
                int mid = nums[left] +nums[right];

                if(sum + mid == 0 ){
                    v.insert({sum,nums[left],nums[right] });
                    left++;
                    right--;
                }else if(sum + mid <0){
                    left++;
                }else if(sum + mid >0) {
                    right--;
                }
            }
        
        
        }
        vector<vector<int>>vv(v.begin(), v.end());
        return vv;
    }
};















// int sum = nums[i];
//         for(int j = i+1 ; j <n-1; j ++){
//             int left =j;
//             for(int k = j+1 ; k <n; k++){
//                 int right = k;
//                 if(sum + nums[left] + nums[right] == 0 && (i !=j) && (i!=k) && (j != k )){
//                     v.insert({sum,nums[left],nums[right]});
//                 }
//             }
//         }
        