class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // vector<int> temp;
        // for(int j=0; j < queries.size(); j++) {
        //     int maxBeauty = 0;

        //     for(int i=0; i < items.size(); i++) {
        //         if(items[i][0] <= queries[j]) {
        //             maxBeauty = max(maxBeauty, items[i][1]);
        //         }
        //     }
        //     temp.push_back(maxBeauty);
        // }
        // return temp;

        vector<int> temp(queries.size(), 0);
        sort(items.begin(), items.end());

        vector<pair<int, int>> query;
        for(int i=0; i < queries.size(); i++) {
            query.push_back({queries[i], i});
        }
        sort(query.begin(), query.end());

        int queryIdx = 0;
        int itemIdx = 0;
        int maxBeauty = 0;
        while(queryIdx < query.size()) {

            while(itemIdx < items.size() && items[itemIdx][0] <= query[queryIdx].first) {
                    maxBeauty = max(maxBeauty, items[itemIdx][1]);
                    itemIdx++;
                }
            temp[query[queryIdx].second] = maxBeauty;
            queryIdx++;
        }
        return temp;
    }
};