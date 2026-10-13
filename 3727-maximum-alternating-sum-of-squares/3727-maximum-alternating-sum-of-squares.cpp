class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> square;
        for(int i=0; i < nums.size(); i++) {
            square.push_back(1LL * nums[i] * nums[i]);  //1LL is used for typecasting to long long.
        }

        sort(square.begin(), square.end(), greater<long long>()); //sort based on magnitude of their squares.

        int i = 0;
        int j = nums.size()-1;
        long long ans = 0;
        while(i < j) {          //the middle element wont get processed, in case of odd sized array
            ans += square[i];
            ans -= square[j];
            i++;
            j--;
        }

        if(i == j) ans += square[i];    //handles the middle element in case of odd sized array
        return ans;
    }
};