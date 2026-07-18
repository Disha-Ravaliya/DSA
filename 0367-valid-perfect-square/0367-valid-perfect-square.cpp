class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <0){return false;}
        int left = 1;
        int right = num;

        while (left <= right) {
           int mid = left + (right - left) / 2;
          long long square = (long long)mid * mid;

            if (square == num)
                return true;
            else if (square < num)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};