class Solution {
public:
    long long countCommas(long long n) {
        long long threshold = 1000;
        long long count = 0;

        while(threshold <= n) {
            count += n - threshold + 1;
            threshold *= 1000;
        }
        return count++;
    }
};