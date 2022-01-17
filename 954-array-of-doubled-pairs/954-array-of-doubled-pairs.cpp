class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map <int, int> count;
        for (int i = 0; i < arr.size(); i++) {
            count[arr[i]]++;
        }
        
        while (true) {
            //cout << count.size() << " ";
            if (count.size() == 0) {
                return true;
            }
            int ele = count.begin()->first;
            //cout << ele << count[ele] << " ";
            if (count[ele] == 1) {
                count.erase(ele);
            } else {
                count[ele]--;
            }
            
            int find = ele * 2;
            if (ele < 0) {
                if (ele % 2 == 0) {
                    find = ele / 2;
                } else {
                    break;
                }
            }
            
            if (count.find(find) == count.end()) {
                break;
            } else {
                if (count[find] == 1) {
                    count.erase(find);
                } else {
                    count[find]--;
                }
            }
        }
        return false;
    }
};