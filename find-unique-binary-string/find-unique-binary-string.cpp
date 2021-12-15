class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector <int> v (nums.size(), 0); // how many times 1 appear
        unordered_set<string> u;
        for (int i = 0; i < nums.size(); i++) {
            string str = nums[i];
            u.insert(nums[i]);
            for (int j = 0; j < str.length(); j++) {
                int num = str[j] - '0';
                if (num == 1) {
                    v[j] += 1;
                }
            }
        }
        string ans = "";
        for (int i = 0; i < nums.size() - 1; i++) {
            if (v[i] == nums.size()) {
                ans.push_back('0');
            } else {
                ans.push_back('1');
            }
        }
        string ans1 = ans + '0';
        string ans2 = ans + '1';
        if (u.find(ans1) == u.end()) {
            return ans1;
        } 
        return ans2;
    }
};