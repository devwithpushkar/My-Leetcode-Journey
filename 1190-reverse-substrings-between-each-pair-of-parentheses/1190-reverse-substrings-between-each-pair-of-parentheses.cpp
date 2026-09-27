class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr = "";

        int i = 0;
        while(i < s.size()) {
            if(s[i] != '(' && s[i] != ')') {
                curr += s[i];
            } else if(s[i] == '(') {
                st.push(curr);
                curr = "";
            } else {
                reverse(curr.begin(), curr.end());
                string temp = curr;
                curr = st.top() + temp;
                st.pop();
            }
            i++;
        }
        return curr;
    }
};