class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int adj = 0;
        bool prev = true;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                cout << "a" << i << " ";
                if (prev == false) {
                    prev = true;
                } else {
                    if (i == flowerbed.size() - 1 || flowerbed[i+1] == 0) {
                        adj += 1;
                        cout << i << " ";
                        prev = false;
                    }
                }
            } else {
                prev = false;
            }
        }
        if (adj >= n) {
            return true;
        }
        return false;
    }
};