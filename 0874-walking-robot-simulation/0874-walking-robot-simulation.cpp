class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        int direction = 0;
        set<pair<int, int>> obs;
        int ans = 0;

        for(int i=0; i < obstacles.size(); i++) {
            obs.insert({obstacles[i][0], obstacles[i][1]});
        }

        for(int c : commands) {
            if(c == -1) { 
                direction = (direction + 1) % 4; //turn right
            } else if(c == -2)  {
                direction = (direction + 3) % 4; 
            //turn left (used +3 to handle negative flow in modulo(%) operation at direction = 0)
            } else {
                if(direction == 0) {
                    for(int i = 0; i < c; i++) {
                        if(obs.count({x, y + 1})) break;
                        y++;
                        ans = max(ans, x*x + y*y);
                    }
                } else if(direction == 1) {
                    for(int i = 0; i < c; i++) {
                        if(obs.count({x + 1, y})) break;
                        x++;
                        ans = max(ans, x*x + y*y);
                    }
                } else if(direction == 2) {
                    for(int i = 0; i < c; i++) {
                        if(obs.count({x, y - 1})) break;
                        y--;
                        ans = max(ans, x*x + y*y);
                    }
                } else {
                    for(int i = 0; i < c; i++) {
                        if(obs.count({x - 1, y})) break;
                        x--;
                        ans = max(ans, x*x + y*y);
                    }
                }
            }
        }
        return ans;
    }
};