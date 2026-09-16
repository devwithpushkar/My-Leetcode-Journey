class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for(int x : digits) {
            freq[x]++;
        }

        int count = 0;

        int temp[10];
        copy(freq, freq + 10, temp);

        for(int i=0; i < 10; i++) {
            temp[i]--;
            for(int j=0; j < 10; j++) {
                temp[j]--;
                for(int k=0; k < 10; k++) {
                    temp[k]--;

                    if(temp[i] < 0 ||
                       temp[j] < 0 ||
                       temp[k] < 0 ||
                       i == 0      ||
                       k % 2 != 0) {
                        temp[k]++;
                        continue;
                       }
                    
                    count++;
                    temp[k]++;
                }
                temp[j]++;
            }
            temp[i]++;
        }
        return count;
    }
};