class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int xLeft = max(rec1[0], rec2[0]);
        int xRight = min(rec1[2], rec2[2]);

        int yBottom = max(rec1[1], rec2[1]);
        int yTop = min(rec1[3], rec2[3]);

        if(xLeft < xRight && yBottom < yTop) return true;
        return false;
    }
};