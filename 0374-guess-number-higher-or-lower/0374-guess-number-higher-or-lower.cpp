class Solution {
public:
    int guessNumber(int n) {

        long long low = 1;
        long long high = n;

        while(low <= high) {

            long long mid = low + (high - low) / 2;

            int result = guess(mid);

            if(result == 0) {
                return mid;
            }
            else if(result == -1) {
                // mid is greater than pick
                high = mid - 1;
            }
            else {
                // mid is smaller than pick
                low = mid + 1;
            }
        }

        return -1;
    }
};