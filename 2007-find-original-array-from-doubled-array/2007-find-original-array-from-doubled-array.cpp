class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map <int, int> count;
        for (int i = 0; i < changed.size(); i++) {
            count[changed[i]]++;
        }
        vector<int> ans;
        while (true) {
            //cout << count.size() << " ";
            if (count.size() == 0) {
                return ans;
            }
            int ele = count.begin()->first;
            //cout << ele << count[ele] << " ";
            ans.push_back(ele);
            if (count[ele] == 1) {
                count.erase(ele);
            } else {
                count[ele]--;
            }
            if (count.find(ele * 2) == count.end()) {
                break;
            } else {
                if (count[ele * 2] == 1) {
                    count.erase(ele * 2);
                } else {
                    count[ele * 2]--;
                }
            }
        }
        vector<int> blank;
        return blank;
    }
};