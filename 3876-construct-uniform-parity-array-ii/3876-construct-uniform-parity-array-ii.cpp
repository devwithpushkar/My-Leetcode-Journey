class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool allEven = false;
        bool allOdd = false;
        for(int i=0; i < nums1.size(); i++) {
            if(nums1[i] % 2 == 0) {  //check for all even, if even a single is odd, change to false and escape
                allEven = true;
            } else {
                allEven = false;
                break;
            }
        }
        for(int i=0; i < nums1.size(); i++) {
             if(nums1[i] % 2 == 1) {  //check for all even, if even a single is odd, change to false and escape
                allOdd = true;
            } else {
                allOdd = false;
                break;
            }
        }
        if(allOdd || allEven) return true;

        int smallestOdd = INT_MAX;
        for(int i=0; i < nums1.size(); i++) {   //obtain the smallest odd
            if(nums1[i] % 2 == 1 && nums1[i] < smallestOdd) smallestOdd = nums1[i];
        }

        for(int i=0; i < nums1.size(); i++) {
            if(nums1[i] % 2 == 0 && (!(smallestOdd < nums1[i]))) return false;
        }
        return true;
    }
};