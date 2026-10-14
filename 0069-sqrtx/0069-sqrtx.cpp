class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        int ans = 0;

        if(x == 0) return x;

        while(left <= right) {
            int mid = left + (right-left) / 2;

            if(1LL * mid * mid == x) {      //1LL is used to handle integer overflow
                return mid;
            } else if(1LL * mid * mid > x) {    //1LL is used to handle integer overflow
                right = mid-1;
            } else {
                ans = mid;
                left = mid+1;
            }
        }
        return ans;
    }
};