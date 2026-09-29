class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> kDigit;
        while(k > 0) {
            int result = k % 10;
            kDigit.push_back(result);
            k /= 10;
        }
        reverse(kDigit.begin(), kDigit.end());

        int i = num.size()-1;
        int j = kDigit.size()-1;
        int carry = 0;
        vector<int> ans;

        while(i >= 0 || j >= 0 || carry) {
            int a = (i >= 0) ? num[i] : 0;
            int b = (j >= 0) ? kDigit[j] : 0;
            int digit = a + b + carry;
            ans.push_back(digit % 10);
            carry = digit / 10;

            i--;
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};