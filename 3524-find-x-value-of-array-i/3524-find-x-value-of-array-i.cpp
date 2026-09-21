class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
       vector<long long> result(k, 0);
       vector<long long> prevCount(k, 0);

        for(int i=0; i < nums.size(); i++) {
            vector<long long> currCount(k, 0);
            
            int currElement = nums[i] % k;
            currCount[currElement]++;

            for(int oldRem = 0; oldRem < k; oldRem++) {
                int newRem = (oldRem * currElement) % k;
                currCount[newRem] += prevCount[oldRem];
            }

            prevCount = currCount;

            for(int i=0; i < k; i++) {
                result[i] += currCount[i];
            }
        }

        return result;
    }
};