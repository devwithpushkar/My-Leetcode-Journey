class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0;    //minimum open brackets 
        int maxOpen = 0;    //maximum open brackets

                    // number of open brackets are in the range [minOpen, maxOpen]

        for(char c : s) {
            if(c == '(') {
                minOpen++;
                maxOpen++;
            }

            if(c == ')') {
                minOpen = max(0, minOpen-1);    //because mininmum Open brackets cannot be negative.
                maxOpen--;
            }

            if(c == '*') {
                minOpen = max(0, minOpen-1);
                maxOpen++;
            }

            if(maxOpen < 0) return false; //for cases like ")))"
        }

        return minOpen == 0;
    }
};