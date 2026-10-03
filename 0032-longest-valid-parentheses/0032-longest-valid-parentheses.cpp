class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0;
        int close = 0;

        int result = 0;

        //checking from left to right
        for(int i=0; i < s.length(); i++) {
            if(s[i] == '(') {
                open++;
            } else {
                close++;
            }

            if(open == close) result = max(result, open + close);

            if(close > open) {  //if a `)` appears before its corresponding `(`, we reset.
                open = 0;
                close = 0;
            }
        }

            //checking from right to left
        open = 0;
        close = 0;

        for(int i=s.length()-1; i >= 0; i--) {
            if(s[i] == ')') {
                close++;
            } else {
                open++;
            }

            if(open == close) result = max(result, open + close);

            if(open > close) {  //if a `(` appears before its corresponding `)`, we reset.
                open = 0;
                close = 0;
            }
        }
            //checking both left to right and right to left takes care of the edge cases like
                        //                  `(()`
        return result;
    }
};