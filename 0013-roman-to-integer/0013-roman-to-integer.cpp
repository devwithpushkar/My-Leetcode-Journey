class Solution {
public:
    int getValue(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }

    int romanToInt(string s) {
        int i = 0;
        int ans = 0;

        while(i < s.size()) {
            if(i != s.size()-1 && getValue(s[i]) < getValue(s[i+1])) {
                ans += (getValue(s[i+1]) - getValue(s[i]));
                i += 2;
            } else {
                ans += getValue(s[i]);
                i++;
            }
        }

        return ans;
    }
};