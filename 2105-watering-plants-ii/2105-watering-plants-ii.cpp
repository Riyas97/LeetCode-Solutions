class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int num = 0;
        int l = 0;
        int r = plants.size() - 1;
        int left = capacityA;
        int right = capacityB;
        while (l <= r) {
            if (l == r) {
                if (left == right) {
                    int m = left;
                    if (plants[l] > m) {
                        num += 1;
                    }
                } else {
                    int m = max(left,right);
                    if (plants[l] > m) {
                        num += 1;
                    }
                }
                
                
                l++;
                r--;
            } else {
                if (plants[l] <= left) {
                    left -= plants[l];
                } else {
                    num += 1;
                    left = capacityA;
                    left -= plants[l];
                }
                
                l++;
                
                if (plants[r] <= right) {
                    right -= plants[r];
                } else {
                    num += 1;
                    right = capacityB;
                    right -= plants[r];
                }
                r--;
            }
        }
        
        
        return num;
    }
};