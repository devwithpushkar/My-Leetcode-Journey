class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cap = nums[0];
        int ans = 0;

        for(int i=0; i < nums.size(); i++) {
            cap = max(cap, nums[i]);
        }

        for(int i=0; i < nums.size(); i++) {
            ans += cap - nums[i];
        }

        return ans;
    }
};