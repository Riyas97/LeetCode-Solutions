class Solution {
public:
    string maxValue(string n, int x) {
        bool isPos = n[0] != '-';
        string ans = "";
        bool added = false;
        
        if (isPos) {
            for (int i = 0; i < n.length(); i++) {
                if (added) {
                    ans.push_back(n[i]);
                } else {
                    int num = n[i] - '0';
                    if (num >= x) {
                        ans.push_back(n[i]);
                    } else {

                        char xx = '0' + x;
                        ans.push_back(xx);
                        ans.push_back(n[i]);
                        added = true;
                    }
                }
            }
        } else {
            for (int i = 0; i < n.length(); i++) {
                if (added || i == 0) {
                    ans.push_back(n[i]);
                } else {
                    int num = n[i] - '0';
                    if (num <= x) {
                        ans.push_back(n[i]);
                    } else {

                        char xx = '0' + x;
                        ans.push_back(xx);
                        ans.push_back(n[i]);
                        added = true;
                    }
                }
            }
        }
        
        if (!added) {
            char xx = '0' + x;
            ans.push_back(xx);
        }
        
        return ans;
    }
};