class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //populate hashmap with `nums1` elements. iterate through `nums2` elements, and if it exists (and the count frequency > 0) push_back to ans vector and decrement count frequency in hashmap.
        vector<int> ans;

        unordered_map<int, int> hash;
        for(int i : nums1) {
            hash[i]++;
        }
        

        for(int x : nums2) {
            auto it = hash.find(x);
            if(it != hash.end()) {
                if(it->second > 0) {
                    ans.push_back(x);
                    it->second--;
                }
            }
        }

        return ans;
    }
};