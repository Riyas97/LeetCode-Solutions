class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector <int> count(3, 0);
        for (int i = 0; i < nums.size(); i += 1) {
            count[nums[i]] += 1;
        }
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (s <= 2 && count[s] == 0) {
                s++;
            }
            nums[i] = s;
            count[s]--;
        } 
    }
};