class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        for(int i =0; i <k; i ++){
            while(dq.size() >0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

        }
        for(int i =k; i <nums.size(); i++){
            ans.push_back(nums[dq.front()]);
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front(); // its not from cuu window 
            }

            while(dq.size() >0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

        }
        ans.push_back(nums[dq.front()]);

        return ans;
        
    }
};