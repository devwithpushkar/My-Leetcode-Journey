class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //instead of finding the number of elements we can remove from the `nums` array, we will find the number of elements we can keep after the complete operation.

        //for eg, if sum(nums) = S, and no. of elements we can remove is y, then the number of elements we can keep is S - y, so the answer must be nums.size() - no. of (y) elements such that sum(y) = x

        int target = accumulate(nums.begin(), nums.end(), 0) - x;

        if(target < 0) return -1;

        int left = 0;
        int sum = 0;
        int maxLength = 0;

        int right = 0;
        
        while(right < nums.size()) {
            sum += nums[right];

            if(sum > target) {
                while(sum > target) {
                    sum -= nums[left];
                    left++;
                }
            }

            if(sum == target) maxLength = max(maxLength, right-left+1);

            right++;
        }
        if (maxLength == 0 && target != 0)
        return -1;

        return nums.size() - maxLength;
    }
};