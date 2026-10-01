class Solution {
public:
    bool checkIfPangram(string sentence) {
        int freq[26] = {0};

        for(char c : sentence) {
            freq[c - 'a']++;
        }

        for(int x : freq) {
            if(x == 0) return false;
        }
        return true;
    }
};