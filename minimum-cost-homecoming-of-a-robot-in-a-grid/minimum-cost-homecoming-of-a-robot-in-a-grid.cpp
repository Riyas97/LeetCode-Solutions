class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int diffR = homePos[0] - startPos[0];
        int diffC = homePos[1] - startPos[1];
        
        int ans = 0;
        
        if (diffR > 0) {
            int count = startPos[0] + 1;
            while (count <= homePos[0]) {
                ans += rowCosts[count];
                count += 1;
            }
        } else if (diffR < 0) {
            int count = startPos[0] - 1;
            while (count >= homePos[0]) {
                ans += rowCosts[count];
                count -= 1;
            }
        }
        
        if (diffC > 0) {
            int count = startPos[1] + 1;
            while (count <= homePos[1]) {
                ans += colCosts[count];
                count += 1;
            }
        } else if (diffC < 0) {
            int count = startPos[1] - 1;
            while (count >= homePos[1]) {
                ans += colCosts[count];
                count -= 1;
            }
        }
        
        return ans;
        
    }
};