class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        int i = 0;
        int j = 0;
        while(j < n) {
            grid[0][j] = '.';
            j++;
        }
        while(i < m) {
            grid[i][n-1] = '.';
            i++;
        }

        return grid;
    }
};