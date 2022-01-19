class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int curr = 1;
        int ans = 0;
        
        while (target > 1 && maxDoubles > 0) {
            if (target % 2 == 0) {
                target /= 2;
            } else {
                ans++;
                target--;
                target /= 2;
            }
            maxDoubles--;
            ans++;
        }
        
        if (target == 1) {
            return ans;
        } else if (target > 1) {
            ans += (target - 1);
            return ans;
        }
        
        return ans;
    }
};