class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 0;
        for(int i=0; i < weights.size(); i++) {
            if(weights[i] > left) left = weights[i];
            right += weights[i];
        }
        
        while(left < right) {
            int capacity = left + (right - left) / 2;
            int currLoad = 0;
            int currDay = 1;

            for(int i=0; i < weights.size(); i++) {
                if(currLoad + weights[i] <= capacity) {
                    currLoad += weights[i];
                } else {
                    currLoad = weights[i];
                    currDay++;
                }
            }
            if(currDay > days) {
                left = capacity + 1;
            } else {
                right = capacity;
            }
        }
        return left;
    }
};