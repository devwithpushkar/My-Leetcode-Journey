class Solution {
public:
    string convertToTitle(int columnNumber) {
        unordered_map<int, char> mp;
        for(int i=0; i < 26; i++) {
            mp[i] = 'A' + i;
        }

        string ans = "";
        
        while(columnNumber > 0) {
            columnNumber--;
            int remainder = columnNumber % 26;
            ans += mp[remainder];
            columnNumber /= 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};