class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int count = 1;

        for(char c : s) {
            ans += (26 - (c - 'a')) * count;
            count++;
        }

        return ans;
    }
};