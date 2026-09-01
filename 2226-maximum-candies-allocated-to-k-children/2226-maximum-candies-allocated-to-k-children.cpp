class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1;   //not left=0 to prevent division by zero in candiees[i] / candyNum (in the case candyNu=0)
        int right = 0;
        for(int i=0; i < candies.size(); i++) {
            if(candies[i] > right) right = candies[i];
        }

        while(left <= right) {  //not while(left < right) { ...} because if left == right, the loop stops but there is still this one candidate left to check where left == right;
            int candyNum = left + (right - left) / 2;
            long long total = 0;

            for(int i=0; i < candies.size(); i++) {
                total += candies[i] / candyNum;
            }

            if(total >= k) {
                left = candyNum + 1;
            } else {
                right = candyNum - 1;
            }
        }
        return right;   //not return left;
    }
};