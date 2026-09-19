class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minVal = nums[0], maxVal = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minVal) {
                minVal = nums[i];
            }
            if (nums[i] > maxVal) {
                maxVal = nums[i];
            }
        }
        
        int result = 1;
        for (int i = 1; i <= minVal; i++) {
            if (minVal % i == 0 && maxVal % i == 0) {
                result = i;
            }
        }
        return result;
    }
};