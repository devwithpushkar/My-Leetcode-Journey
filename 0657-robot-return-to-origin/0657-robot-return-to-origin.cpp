class Solution {
public:
    bool judgeCircle(string moves) {
        int row = 0;
        int col = 0;

        for(char c : moves){
            if(c== 'U') row--;
            else if(c == 'D') row++;
            else if(c == 'L') col--;
            else if(c == 'R') col++;
        }

        return row == 0 && col == 0;
    }
};