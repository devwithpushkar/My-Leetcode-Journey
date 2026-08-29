class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.length() / rows;
        int startCol = 0;
        vector<char> ans;

        while(startCol < cols) {
            int row = 0;
            int col = startCol;

            while(row < rows && col < cols) {
                ans.push_back(encodedText[row * cols + col]);
                row++;
                col++;
            }
            startCol++;
        }

        while(!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        string s(ans.begin(), ans.end());
        return s;
    }
};