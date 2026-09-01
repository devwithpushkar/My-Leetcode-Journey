class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        for(int i=0; i < nums.size(); i++) {
            if(nums[i] > left) left = nums[i];
            right += nums[i];
        }

        while(left <= right) {
            int maxSum = left + (right - left) / 2;
            int currSum = 0;
            int currSubArray = 1;

            for(int i=0; i < nums.size(); i++) {
                if(currSum + nums[i] <= maxSum) {
                    currSum += nums[i];
                } else {
                    currSum = nums[i];
                    currSubArray++;
                }
            }

            if(currSubArray <= k) {
                right = maxSum - 1;
            } else {
                left = maxSum + 1;
            }
        }
        return left;
    }
};