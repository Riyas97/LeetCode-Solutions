class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_map <string, int> um;
        sort(words.begin(), words.end());
        for (int i = 0; i < words.size(); i++) {
            string last = words[i].substr(
                0, words[i].length() - 1);
            if (um.find(last) != um.end()) {
                um[words[i]] = 1 + um[last];
            } else if (words[i].length() == 1) {
                um[words[i]] = 1;
            }
        }
        
        int mnum = -1;
        string ans = "";
        for (auto it = um.begin(); it != um.end(); it++) {
            string str = it->first;
            int num = it->second;
            //cout << num << " " << str << " " << "\n";
            if (num > mnum) {
                mnum = num;
                ans = str;
                //cout << mnum << " " << ans << " " << "\n";
            } else if (num == mnum) {
                if (str < ans) {
                    //cout << "rig" << str << " " << ans << "\n";
                    ans = str;
                } else {
                    //cout << "no" << str << " " << ans << "\n";
                }
            }
        }
        return ans;
    }
};