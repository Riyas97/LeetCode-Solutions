class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int s = 0;
        int e = height.size() - 1;
        int d = height.size() - 1;
        while (d > 0) {
            area = max(area, min(height[s], height[e]) * d);
            
            if (height[s] < height[e]) {
                s += 1; 
            } else {
                e -= 1;
            }
            
            d -= 1;
        }
        return area;
    }
};