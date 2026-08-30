class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = 0;
        int maxIdx = 0;
        int ans = INT_MAX;

        if(nums.size() == 1) return 1;

        for(int i=0; i < nums.size(); i++) {
            if(nums[i] < nums[minIdx]) minIdx = i;
            if(nums[i] > nums[maxIdx]) maxIdx = i;
        }

        // //case 1 both from the front;
        // int d1 = max(minIdx, maxIdx) + 1;
        
        // //case 2 both from the back;
        // int d2 = nums.size() - min(minIdx, maxIdx);

        // //case 3 (a) min from front, max from back;
        // int d3 = (minIdx + 1) + (nums.size() - maxIdx);

        // //case 4 (b) max from front, min from back;
        // int d4 = (maxIdx + 1) + (nums.size() - minIdx);
        
        // ans = min({d1, d2, d3, d4});

        int start = min(minIdx, maxIdx);
        int end = max(minIdx, maxIdx);

        int d1 = end + 1;
        int d2 = nums.size() - start;
        int d3 = (start + 1 + (nums.size() - end));

        ans = min({d1, d2, d3});

        return ans;
    }
};