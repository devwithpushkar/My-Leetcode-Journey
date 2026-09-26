class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> hash;
        for(int i=0; i < knowledge.size(); i++) {
            string key = knowledge[i][0];
            string value = knowledge[i][1];

            hash[key] = value;
        }

        string ans = "";
        int i = 0;

        while(i < s.size()) {
            if(s[i] != '(') {

                ans += s[i];
                i++;

            } else {

                int j = i+1;
                string key = "";
                while(s[j] != ')') {
                    key += s[j];
                    j++;
                }

                if(hash.count(key) != 0) {
                    ans += hash[key];
                } else {
                    ans += "?";
                }
                
                i = j+1;
            }
        }
        return ans;
    }
};