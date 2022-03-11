class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.length() < 10) {
            return ans;
        }
        unordered_map<string, int> count;
        for (int i = 0; i <= s.length() - 10; i++) {
            string substr = s.substr(i, 10);
            count[substr]++;
            if (count[substr] == 2) {
                ans.push_back(substr);
            }
        }
        return ans;
    }
};