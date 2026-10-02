class Solution {
public:
    void solve(string& current, int open, int close, int n, vector<string>& ans) {
        if(open == n && close == n) {
            ans.push_back(current);
            return;
        }

        if(open < n) {
            current += "(";
            open++;

            solve(current, open, close, n, ans);
            open--;
            current.pop_back();
        }

        if(close < open) {
            current += ")";
            close++;

            solve(current, open, close, n, ans);
            close--;
            current.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current = "";
        int open = 0;
        int close = 0;

        solve(current, open, close, n, ans);

        return ans;
    }
};