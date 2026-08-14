class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        //here*max_element is return max in this container ,it  not return value , it return iterator pointer

        int maxi = *max_element(candies.begin(), candies.end());

        vector<bool> ans;

        for(int i = 0; i < candies.size(); i++) {

            if(candies[i] + extraCandies >= maxi) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};