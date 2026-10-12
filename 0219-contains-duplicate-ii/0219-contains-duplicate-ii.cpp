class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hash;
        for(int i=0; i < nums.size(); i++) {
            if(hash.find(nums[i]) != hash.end()) return true;

            hash.insert(nums[i]);

            if(i >= k) {
                hash.erase(nums[i-k]);
            }
        }
        return false;
    }
};