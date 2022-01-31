class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int prev = 1;
        for (int i = 0; i < target.size(); i++) {
            for (int j = prev; j < target[i]; j++) {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            ans.push_back("Push");
            prev = target[i] + 1;
        }
        return ans;
    }
};