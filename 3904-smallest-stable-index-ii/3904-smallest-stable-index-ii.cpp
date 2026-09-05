class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int prefix = INT_MIN;
        vector<int> suffix(nums.size());
        suffix[nums.size()-1] = nums[nums.size()-1];
        int ans = INT_MAX;

        for(int i=nums.size()-2; i >= 0; i--) {   //populate the suffix vector.
            if(nums[i] < suffix[i+1]) {
                suffix[i] = nums[i];
            } else {
                suffix[i] = suffix[i+1];
            }
        }

        for(int i=0; i < nums.size(); i++) {
            if(nums[i] > prefix) {
                prefix = nums[i];
            }
            
            int temp = prefix - suffix[i];
            if(temp <= k) {
                return i;
            }
        }

        return -1;
    }
};